// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/LeptonFinder.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/DirectFinalState.hh"

namespace Rivet {


  /// @brief Add a short analysis description here
  class ROUTINE_COUPURES : public Analysis {
  public:

    /// Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(ROUTINE_COUPURES);


    /// @name Analysis methods
    /// @{

    /// Book histograms and initialise projections before the run
    void init() {

      const FinalState fs(Cuts::abseta < 4.9);
      FastJets jetfs(fs, JetAlg::ANTIKT, 0.4);
      declare(jetfs, "jets");

      // Histogramme du pT du leading jet
      
      book(_h["ETA_J1"], "eta_jet1_cut", 20, -5.0, 5.0);  // 20 bins en eta de -5 a 5

      // Compteurs d'efficacite
      book(_c["ALL"], "count_all");
      book(_c["PT60"], "count_pt");
      book(_c["ETAcut"], "count_eta");
      book(_c["ALLCUTS"], "count_allcuts");

    }





    /// Perform the per-event analysis
    void analyze(const Event& event) {
      _c["ALL"]->fill();

      const Jets jets = apply<FastJets>(event, "jets").jetsByPt();
      if (jets.empty()) return;

      const Jet& j1 = jets[0];

      // Cut indépendant sur pT
      if (j1.pT() > 60*GeV)
        _c["PT60"]->fill();

      // Cut indépendant sur eta
      if (j1.abseta() > 2.5 && j1.abseta() < 4.0)
        _c["ETAcut"]->fill();

      // Cut combiné
      if (j1.pT() > 60*GeV && j1.abseta() > 2.5 && j1.abseta() < 4.0) {
        _c["ALLCUTS"]->fill();
        _h["ETA_J1"]->fill(j1.eta());
  }
}





    /// Normalise histograms etc., after the run
    void finalize() {
      // Normalisation de l'histogramme a la section efficace en pb/GeV
      double binWidth = (_h["PT_J1"]->xMax() - _h["PT_J1"]->xMin()) / _h["PT_J1"]->numBins();
      scale(_h["ETA_J1"], crossSection() / sumOfWeights());

      // Affichage des efficacites
      const double Ntot = _c["ALL"]->val();
      const double eff_pt = _c["PT60"]->val() / Ntot;
      const double eff_eta = _c["ETAcut"]->val() / Ntot;
      const double eff_total = _c["ALLCUTS"]->val() / Ntot;

      MSG_INFO("Efficacite pT > 60 GeV       = " << eff_pt);
      MSG_INFO("Efficacite 2.5 < |eta| < 4.0   = " << eff_eta);
      MSG_INFO("Efficacite combinee          = " << eff_total);
    }

    private:
    map<string, Histo1DPtr> _h;
    map<string, CounterPtr> _c;
  };


  RIVET_DECLARE_PLUGIN(ROUTINE_COUPURES);

}
