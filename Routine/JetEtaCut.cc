// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"

namespace Rivet {

  class JetEtaCut : public Analysis {
  public:

/// Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(JetEtaCut);

    void init() {
      FinalState fs;
      declare(fs, "FS");

      FastJets fj(fs, JetAlg::ANTIKT, 0.4);
      declare(fj, "Jets");

      book(_h_eta, "jet_eta_cut", 40, -5.0, 5.0);
    }

    void analyze(const Event& event) {
      const Jets& jets = apply<FastJets>(event, "Jets").jetsByPt();
      if (jets.empty()) return;

      const double eta = jets[0].eta();
      if (fabs(eta) > 2.5 && fabs(eta) < 4.0)
        _h_eta->fill(eta);
    }

    void finalize() {
    if (crossSection() > 0 && sumOfWeights() > 0)
      scale(_h_eta, crossSection() / sumOfWeights());
    else
      scale(_h_eta, 1.0);
}


  private:
    Histo1DPtr _h_eta;
  };

  RIVET_DECLARE_PLUGIN(JetEtaCut);

}
