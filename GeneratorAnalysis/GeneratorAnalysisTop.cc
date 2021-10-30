void GeneratorAnalysisTop(){

	TFile *fin1 = new TFile("pptt.root");
	TTree *tree1 = (TTree*)fin1->Get("T");
	//1000	
	int    event1;
	int    npart1;
	int    pdg1[4];
	double px1[4];//[npart(q,qbar,m,mbar)]
	double py1[4];//[npart]
	double pz1[4];//[npart]
	double p1[4];//[npart]
	double E1[4];//[npart]
	double M1[4];//[npart]

	tree1->SetBranchAddress("event",&event1);
	tree1->SetBranchAddress("pdg",&pdg1);
	tree1->SetBranchAddress("npart",&npart1);
	tree1->SetBranchAddress("px",&px1);
	tree1->SetBranchAddress("py",&py1);
	tree1->SetBranchAddress("pz",&pz1);
	tree1->SetBranchAddress("en",&E1);
	tree1->SetBranchAddress("ma",&M1);
	

	TLorentzVector particle1(0.,0.,0.,0.);

	  TH1F *eta1 = new TH1F("eta1","",40,-5.,5.);
	  TH1F *pT1 = new TH1F("pT1","",40,0.,2000.);
	  TH1F *P1 = new TH1F("P1","",40,0.,2000.);
	  TH1F *Energy1 = new TH1F("E1","",40,0.,2000.);
	  TH1F *Et1 = new TH1F("Et1","",40,0.,2000);

	  TH1F *sChannel = new TH1F("sChannel","",40,0,2000);
	 
	for(int n = 0; n<tree1->GetEntries() ; n++){
		
	  tree1->GetEntry(n);
	  for(int i=0;i<npart1;i++){
		if(abs(pdg1[i])==6){
		  particle1.SetPxPyPzE(px1[i],py1[i],pz1[i],E1[i]);
		  eta1->Fill(particle1.Eta());
		  pT1->Fill(particle1.Pt());
		  P1->Fill(particle1.P());
		  Energy1->Fill(particle1.E());
		  Et1->Fill(particle1.Et());
		 }
	  }
	  
	}
	TCanvas *c = new TCanvas("c","",600,600);
        gStyle->SetOptStat(0);

	pT1->Draw();
	pT1->SetXTitle("Tranverse momentum(GeV)");
	pT1->SetYTitle("Entries");
        pT1->SetLineColorAlpha(46,1.5);
        mgr::SetSinglePad(c);
        mgr::SetAxis(pT1);
	c->SaveAs("ToppT.pdf");


	Energy1->Draw();
	Energy1->SetXTitle("Energy(GeV)");
	Energy1->SetYTitle("Entries");
        mgr::SetSinglePad(c);
        mgr::SetAxis(Energy1);
	c->SaveAs("TopEnergy.pdf");

	eta1->Draw();
	eta1->SetXTitle("Eta");
	eta1->SetYTitle("Entries");
        mgr::SetSinglePad(c);
        mgr::SetAxis(eta1);
	c->SaveAs("TopEta.pdf");
	
	Et1->Draw();
	Et1->SetXTitle("Tranverse Energy(GeV)");
	Et1->SetYTitle("Entries");
        mgr::SetSinglePad(c);
        mgr::SetAxis(Et1);
	c->SaveAs("TopEt.pdf");
		
	P1->Draw();
	P1->SetXTitle("momentum(GeV)");
	P1->SetYTitle("Entries");
        mgr::SetSinglePad(c);
        mgr::SetAxis(P1);
	c->SaveAs("TopP.pdf");

}
