# Long-Lived Particles Feasibility Study at ATLAS

![C++](https://img.shields.io/badge/c++-%2300599C.svg?logo=c%2B%2B&logoColor=white) ![Python](https://img.shields.io/badge/python-ffdd54?logo=python&logoColor=4f68a8) ![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?logo=docker&logoColor=white)

This repo contains the simulation framework and analysis routines developed during my Master 2 research internship at the Laboratoire de Physique de Clermont, focused on assessing the observability of Long-Lived Particles with the upgraded ATLAS detector at the High-Luminosity LHC.

## Context

The Standard Model (SM) successfully describes fundamental interactions but cannot account for dark matter, matter-antimatter asymmetry, or neutrino masses. Many Beyond Standard Model (BSM) theories predict Long-Lived Particles, which are particles with macroscopic decay lengths due to suppressed couplings or restricted phase space. These particles decay far from the primary vertex, producing displaced vertices or kinked tracks that standard reconstruction algorithms often miss.

The particle lifetime $\tau$ relates to its decay width $\Gamma$ through the uncertainty principle:

$$\tau = \frac{\hbar}{\Gamma}$$

where the decay width follows from phase space integration:

$$\Gamma = \int \frac{1}{2m_1} \left( \prod_{k=1}^{n} \frac{d^3p'_k}{(2\pi)^3 2E'_k} \right) (2\pi)^4 \delta^{(4)} \left( p_1 - \sum_{k=1}^{n} p'_k \right) |M_{fi}|^2$$

Long lifetimes arise when $|M_{fi}|^2$ is suppressed (weak couplings) or when phase space is restricted (nearly degenerate masses).

## Hidden Abelian Higgs Model

The study uses the Hidden Abelian Higgs Model, a simplified BSM framework that introduces a new $U(1)$ gauge symmetry and a hidden scalar field $\phi_H$ that mixes with the SM Higgs. After spontaneous symmetry breaking, this produces two mass eigenstates: a SM-like Higgs $h$ and a heavier scalar $H$. The heavy scalar decays into pairs of light scalars $h_2$ (the LLPs), which subsequently decay into SM fermions.

### Model implementation challenges

The project initially attempted to use a custom HAHM implementation developed at LPC for studying asymmetric LLP decays. This version included two distinct hidden scalars $s_1$ and $s_2$ with different masses and lifetimes. However, this model proved incomplete for the current analysis because it lacked certain elementary particles required for the VH production channels. Specifically, the custom model's particle content was insufficient to properly simulate the associated production mechanism where the hidden Higgs is produced alongside W or Z bosons.

The solution was to switch to the more complete `HAHM_variableMW_v3_UFO` model, which includes the full SM particle spectrum alongside the hidden sector. This version was implemented using FeynRules and exported in Universal FeynRules Output format for compatibility with MadGraph5. The model parameters include:
- `mhinput`: SM Higgs mass (125 GeV)
- `mhsinput`: LLP mass (varied as 10, 30, 55 GeV)
- `epsilon`: Kinetic mixing parameter ($10^{-10}$)
- `kap`: Portal coupling ($10^{-4}$)

## Event gen pipeline

The full Monte Carlo workflow consists of three stages, each handling different aspects of the collision process:

### Parton-level generation with MadGraph5

MadGraph5 aMC@NLO computes hard scattering matrix elements at tree level. The process definition for the W+h channel is:

```python
import model HAHM_variableMW_v3_UFO
define l+ = e+ mu+ ta+
define l- = e- mu- ta-
generate p p > w- h, (w- > l- vl~), (h > h2 h2, h2 > f f, h2 > f f)
set nevents = 5000
set mhsinput 10
set ebeam1 6800
set ebeam2 6800
```

The beam energy of 6800 GeV per proton corresponds to the HL-LHC design center-of-mass energy of $\sqrt{s} = 13.6$ TeV. Loop-induced processes like gluon fusion are approximated using effective vertices where the top quark loop is replaced by a contact interaction between gluons and the Higgs. This effective theory approach is standard in phenomenological studies and provides accurate results for Higgs transverse momentum distributions below approximately 200 GeV.

### Parton shower and hadronization with PYTHIA 8

PYTHIA 8 evolves the parton-level events through QCD showering via the Lund string model. The showering algorithm uses the DGLAP evolution equations to model successive gluon emissions down to the hadronization scale ($\sim 1$ GeV). Color confinement is implemented through string fragmentation, which produces the observed hadrons. PYTHIA also handles particle decays, including the configurable LLP decay channels. The output is stored in HEPMC format, containing full particle four-momenta, vertex positions, and status codes.

### Analysis with Rivet

Rivet processes the HEPMC events through C++ analysis routines. The primary analysis used the built-in `MC_JETS` routine, which implements configurable jet reconstruction:

```cpp
void init() {
    const double jetptcut = getOption<double>("PTJMIN", 20.0);
    _jetptcut = jetptcut * GeV;
    
    const double R = getOption<double>("R", 0.4);
    
    JetAlg clusterAlgo = JetAlg::ANTIKT;  // default
    
    FinalState fs;
    FastJets jetpro(fs, clusterAlgo, R);
    declare(jetpro, "Jets");
}
```

The `MC_JETS` routine accepts runtime options that control jet reconstruction parameters. For this study, the transverse momentum cut was applied directly through the `PTJMIN` option:

```bash
rivet -a MC_JETS:PTJMIN=60 signal.hepmc.gz -o analysis_output.yoda --skip-weight
```

This approach leverages the routine's built-in $p_T$ threshold option, applying the 60 GeV cut during jet reconstruction rather than as a post-processing filter. The `MC_JETS` routine also supports other options like `R` (jet radius, default 0.4) and `ALGO` (clustering algorithm: KT, CA, or ANTIKT).

For the pseudorapidity cut, I developed a custom Rivet routine to isolate the forward region $2.5 < |\eta| < 4.0$:

```cpp
void analyze(const Event& event) {
    const Jets& jets = apply<FastJets>(event, "Jets").jetsByPt();
    if (jets.empty()) return;
    
    const double eta = jets[0].eta();
    if (fabs(eta) > 2.5 && fabs(eta) < 4.0)
        _h_eta->fill(eta);
}
```

However, correctly normalizing the histograms when combining the signal and background samples proved more difficult than expected. I was only able to produce a pseudorapidity distribution for the VH channel.

## Workflow automation strategy

Generating events for multiple LLP masses and production channels required systematic automation. The workflow was managed through a hierarchy of bash scripts.

### Parameter space coverage

The full parameter space consisted of:
- 3 LLP masses: 10, 30, 55 GeV
- 2 production modes: ggH and VH (split into WH and ZH)
- Background samples: QCD dijets and top pair production

Each configuration required separate MadGraph5 runs followed by PYTHIA showering and Rivet analysis. To avoid manual execution of dozens of jobs, the scripts were structured to:

1. Generate MadGraph5 command files from templates
2. Execute MadGraph5 with automatic PYTHIA interfacing
3. Run Rivet analysis on the resulting HEPMC files
4. Collect YODA output files for plotting

The automation scripts also handled output file naming conventions to keep different configurations organized. For example, events were stored as `signal40.hepmc.gz` and analysis results as `ppZH_lepton_neutrino_55.yoda`.

### plotting

After all YODA files were produced, histograms were normalized and combined using `yodascale` to ensure consistent cross-section weighting across different samples:

```bash
yodascale -c '.* 1' ppZH_lepton_neutrino_10_PTcut60.yoda
                    ppZH_lepton_neutrino_30_PTcut60.yoda \
                    ppWpmH_lepton_30_PTcut60.yoda \
                    ppWpmH_lepton_10_PTcut60.yoda \
                    ppjj_skipweight_PTcut60.yoda
```

Comparison plots were then generated using `rivet-mkhtml`, which produces interactive HTML pages with overlaid distributions:

```bash
rivet-mkhtml ppZH_lepton_neutrino_10_PTcut60-scaled.yoda:ppZH_10 \
             ppZH_lepton_neutrino_30_PTcut60-scaled.yoda:ppZH_30 \
             ppWpmH_lepton_30_PTcut60-scaled.yoda:ppWpm_30 \
             ppWpmH_lepton_10_PTcut60-scaled.yoda:ppWpm_10  \
             ppjj_skipweight_PTcut60-scaled.yoda:ppjj  \
             -o VH_jj_pTcut60
```

The `rivet-mkhtml` command automatically generates Python plotting scripts alongside the HTML output. The utility script `update_jet_pt_xlims.sh` allowed batch modification of axis ranges in these generated scripts:

```bash
for f in jet_pT_*.py; do
  if grep -q "xLims = (20.0" "$f"; then
    sed -i 's/xLims = (20.0/xLims = (55.0/' "$f"
    python3 "$f"
  fi
done
```

## Results and kinematic observables

The analysis focused on three distributions for the leading jet:

**Jet mass**: Light LLPs (10 GeV) exhibit a resonance peak near the expected mass. The VH channels show additional structure at 80-90 GeV from W/Z decays that are occasionally reconstructed as the leading jet. Heavier LLPs produce broader distributions as phase space effects become more pronounced.

**Transverse momentum**: The $p_T$ spectrum peaks around 60-70 GeV for 10 GeV LLPs, shifting lower for heavier masses. This reflects the reduced boost when heavier LLPs are produced near threshold. A cut at $p_T > 60$ GeV was chosen based on this separation, retaining approximately 61% of signal while reducing QCD background to 7% of its initial rate.

**Pseudorapidity**: Distributions are central-dominated with maxima near $\eta = 0$, but significant tails extend into the forward region. The cut $2.5 < |\eta| < 4.0$ isolates the new acceptance region enabled by the ITk and HGTD upgrades. This selection captures an additional 16% of signal that would be inaccessible with the current detector geometry limited to $|\eta| < 2.5$.

## ATLAS Phase-II upgrade context

The Inner Tracker (ITk) will replace the current Inner Detector with an all-silicon system extending coverage to $|\eta| < 4.0$. The High Granularity Timing Detector (HGTD) will provide 30 ps timing resolution in the forward region, enabling 4D vertex reconstruction to separate pile-up interactions and identify delayed decays. These upgrades are essential for LLP searches because many decay products are emitted at small angles relative to the beam axis, precisely where the new instrumentation will be installed.

## Limitations and future directions

This analysis operates at generator level without full detector simulation. Displaced vertex reconstruction algorithms, multivariate selection techniques, and broader scans over LLP mass and lifetime parameters would provide a more complete phenomenological picture.
