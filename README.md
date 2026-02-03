# Long-Lived Particles Feasibility Study at ATLAS

![C++](https://img.shields.io/badge/c++-%2300599C.svg?logo=c%2B%2B&logoColor=white) ![Python](https://img.shields.io/badge/python-ffdd54?logo=python&logoColor=4f68a8) ![Bash](https://img.shields.io/badge/Bash-4EAA25.svg?logo=gnubash&logoColor=3e4549) ![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?logo=docker&logoColor=white) ![Pythia8](https://img.shields.io/badge/Pythia8-%23eba047?logo=data:image/png;base64,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) ![MadGraph5](https://img.shields.io/badge/MadGraph5-%23eeaa89?logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABoAAAAaCAMAAACelLz8AAAAIGNIUk0AAHomAACAhAAA+gAAAIDoAAB1MAAA6mAAADqYAAAXcJy6UTwAAAIlUExURf///+np6r6+vpqamomJiYCAgIyMjKGhocvLy/Pz89/f36CgoHl5eYKCgpCQkJubm3V1dZKSkoGBgbCwse7u7vj4+LKysoeHh6enp6WlpdHR0cHBwZiYmJWVlczMzI2NjXp6esrKypycnK+vr+fn6LGxscfHx87OzsPDw7CwsNbW1rS0tMDAwH19ffv7+/f39+Li47Gxsrm5ucLCwtPT08/Pz7Ozs7u7u7i4uKioqMXFxv7+/o6OjqOjo+Li4tXV1cvLzMjIyM3NzrW1taysrL29vdTU1Lq6upmZmdvb24SEhKmpqc/P0NDQ0OTk5Obm5tra2sTExLy8vKurq7e3t5+fn+zs7P39/a6urr+/v+Pj44uLi11dXVlZWV9fX6amptDPz83NzdLS0sXFxeDg4Orq6uHh4VVVVUdHRwMDAwAAAAUFBZGRkfb29tfX14+Pj+/v76SkpPz8/OHi4t7e3nR0dGtra2VlZWlpaeXl5cbGxvT09JeXl2dnZ9jY2P7+/9bW12BgYGRkZC4uLm1tbd3d3VNTU1xcXEZGRlJSUtzc3IiIiLa2ttPT1Ofn5+jo6FRUVIWFheLh4pSUlLu7vIqKitnZ2UBAQOvr6z09PUNDQ2JiYlhYWOTk5fn5+erq6zs7O62trfX19c7Oz39/f6Kiond3d/z8/cnJyYyMjbu8vJ2dnampqtfX2MPDxIODg5aWlp6enqqqqvHx8czMzXx8fIaGhkgqMaIAAAABYktHRACIBR1IAAAAB3RJTUUH6gEGEwoPFzAMGgAAAntJREFUKM9VkvlbEnEQxidALsOUYtFd1NC4BLFwVyVwNwLSFf2CoaLrFYh2eaSZCR6VuZZooplml2WnZXZZ/X2hVk/ND/PM836emWeedwbgdxwQCEVpaWKJVAb/hzz9oEKUcUiRmaVQHj7yD1BhCnU2loMTmlxVnjD/qPYvkRUoC4/p9HqD0aQrEpgtxZmYdZ+UCIXHTSdspSRlLCsvN1TYT2YoTY49VOispBnylAtnTrvNOo/3TFVFdbFrl7A1FpuvVlonR/4AUW88G6wgG4yNNU0AocbmFkwrZThUrmlta+/oLD0Xjki7JCaAqLMbWC3OcT3q8xcuXrrcK6cNJOrrH7gC2OAQXNUPcyhwrU00cn1UH0NsvBvGxuMwTkCIiXAcwidGCbONQRzHUZM3HM2DIL4J1khK8Le03Zq6PR1HiEMkMwQCIaijYKVwNsBLZu503J0diScCrKFeBl4hzMnBWhfhE7wxfd7QlTk7niopqQo8Psi/B1YyNRAtJP28XLi4dB8hsihUskxB9QMI9ad255t92uHh3JkVmqPDq5DXK4OqdAfQLh6ttj9U6L3T7aYYCrjWmlpT7iNxDFQRio7NP3r8pOOpiEVRw+qzjOA6gDXbA/A8TPbEbIsvpioTCxxuLKvZeLlrL62eBEi+olhU5Jx4Xf2mV/l2ILy+d5N3gta1btaLb+IMRXSKlO99H2pTcsKbSn12caF5K++jlxJY+rc/Ia2/TOXYFBG7fWO+YolHo94uFczrGtwNhIuPSlao/ZnrlrSsrSBNFDSGMbc7rK/8bE86/nxOMrikcH5ZWbZjXzVzc9+i1n8/ced7jlj5Q/kzayOys6/8AmUcoaPqxA3UAAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDI2LTAxLTA2VDE5OjA5OjUwKzAwOjAwVHEb/gAAACV0RVh0ZGF0ZTptb2RpZnkAMjAyNi0wMS0wNlQxOTowOTo1MCswMDowMCUso0IAAAAodEVYdGRhdGU6dGltZXN0YW1wADIwMjYtMDEtMDZUMTk6MTA6MTUrMDA6MDCZ0FfKAAAAAElFTkSuQmCC) ![LaTeX](https://img.shields.io/badge/latex-%23008080.svg?logo=latex&logoColor=white)

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

MadGraph5 aMC@NLO computes hard scattering matrix elements at tree level. The process definition for the W-h channel is:

```python
import model HAHM_variableMW_v3_UFO
define l+ = e+ mu+ ta+
define l- = e- mu- ta-
generate p p > w+ h, (w+ > l+ vl), (h > h2 h2, h2 > f f, h2 > f f)
add process p p > w- h, (w- > l- vl~), (h > h2 h2, h2 > f f, h2 > f f)
...

set nevents = 50000
set mhsinput 10
set ebeam1 6800
set ebeam2 6800
...
```

The proton beam energy of 6800 GeV corresponds to the LHC Run 3 center-of-mass energy of $\sqrt{s} = 13.6$ TeV. Loop-induced processes like gluon fusion are approximated using effective vertices where the top quark loop is replaced by a contact interaction between gluons and the Higgs. This effective theory approach is standard in phenomenological studies and provides accurate results for Higgs transverse momentum distributions below approximately 200 GeV.

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
