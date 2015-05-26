#include "MitMonoPhoton/Mods/interface/ElePhotonDisambiguition.h"

ClassImp(mithep::ElePhotonDisambiguition)

namespace mithep {

  ElePhotonDisambiguition::ElePhotonDisambiguition(char const* name, char const* title) :
    BaseMod(name, title),
    fPhotonsName("Photons"),
    fPhotons(0),
    hHasPixelSeed(0)
  {
  }

  ElePhotonDisambiguition::~ElePhotonDisambiguition()
  {
  }

  void
  ElePhotonDisambiguition::Process()
  {
    LoadBranch(fPhotonsName);

    if (!fPhotons) {
      std::cerr << "Failed to load photons" << std::endl;
      return;
    }

    for (unsigned iP(0); iP != fPhotons->GetEntries(); ++iP) {
      mithep::Photon const& pho(*fPhotons->At(iP));

      hHasPixelSeed->Fill(pho.HasPixelSeed());
    }
  }

  void
  ElePhotonDisambiguition::SlaveBegin()
  {
    AddTH1(hHasPixelSeed, "HasPixelSeed", "HasPixelSeed", 2, 0., 2.);
    
    ReqBranch(fPhotonsName, fPhotons);
  }

  void
  ElePhotonDisambiguition::SlaveTerminate()
  {
  }

}
