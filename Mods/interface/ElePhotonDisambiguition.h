#ifndef MITEXAMPLE_MODS_ELEPHOTONDISAMBIGUITION_H
#define MITEXAMPLE_MODS_ELEPHOTONDISAMBIGUITION_H

#include "MitAna/TreeMod/interface/BaseMod.h"
#include "MitAna/DataTree/interface/PhotonCol.h"

#include "TH1D.h"
#include "TString.h"

namespace mithep {
  
  class ElePhotonDisambiguition : public BaseMod {
  public:
    ElePhotonDisambiguition(char const* name = "ElePhotonDisambiguition", char const* title = "e/gamma disambiguition");
    ~ElePhotonDisambiguition();

  protected:
    void Process() override;
    void SlaveBegin() override;
    void SlaveTerminate() override;

    TString fPhotonsName;

    mithep::PhotonCol const* fPhotons;

    TH1D* hHasPixelSeed;

    ClassDef(ElePhotonDisambiguition, 0)
  };

}

#endif
