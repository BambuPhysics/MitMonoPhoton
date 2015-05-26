import ROOT

ROOT.gSystem.Load('libMitAnaTreeMod.so')
ROOT.gSystem.Load('libMitMonoPhotonMods.so')

mithep = ROOT.mithep

analysis = mithep.Analysis()
analysis.SetOutputName('ElePhoton_GJets.root')

#catalog = mithep.Catalog('/home/cmsprod/catalog')
#dataset = catalog.FindDataset('t2mit/filefi/040', 'WJetsToLNu_13TeV-madgraph-pythia8-tauola+Phys14DR-PU20bx25_PHYS14_25_V1-v1+AODSIM', '0000', 2)
#dataset = catalog.FindDataset('t2mit/filefi/032', 's12-wjets-ptw100-v7c', '0000', 2)
#analysis.AddDataset(dataset)
#analysis.SetUseCacher(1)
analysis.AddFile('/mnt/hadoop/cms/store/user/paus/filefi/040/GJets_HT-100to200_Tune4C_13TeV-madgraph-tauola+Phys14DR-PU20bx25_PHYS14_25_V1-v1+AODSIM/FE3CC0D3-8272-E411-A9F5-002590DB041E.root ')
analysis.SetProcessNEvents(1000)

elePhoton = mithep.ElePhotonDisambiguition()
analysis.AddSuperModule(elePhoton)

analysis.Run(False)
