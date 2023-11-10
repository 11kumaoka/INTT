#ifndef INTT_PRODUCTION_JB_H
#define INTT_PRODUCTION_JB_H

#include "InttHitJb.h"

#include <fun4all/SubsysReco.h>

#include <map>
#include <string>
#include <vector>

#include <TFile.h>
#include <TTree.h>

class PHCompositeNode;

class InttProductionJb : public SubsysReco
{
public:
	InttProductionJb(std::string const& = "InttProductionJb");
	~InttProductionJb() override;

	// Called during initialization.
	// 	Typically this is where you can book histograms, and e.g.
	// 	register them to Fun4AllServer (so they can be output to file
	// 	using Fun4AllServer::dumpHistos() method).
	int Init(PHCompositeNode*) override;

	// Called for first event when run number is known.
	// 	Typically this is where you may want to fetch data from
	// 	database, because you know the run number. A place
	// 	to book histograms which have to know the run number.
	int InitRun(PHCompositeNode*) override;

	// Called for each event.
	// 	This is where you do the real work.
	int process_event(PHCompositeNode*) override;

	// Clean up internals after each event.
	int ResetEvent(PHCompositeNode*) override;

	// Called at the end of each run.
	int EndRun(const int runnumber) override;

	// Called at the end of all processing.
	int End(PHCompositeNode*) override;

	// Reset
	int Reset(PHCompositeNode*) override;

	void Print(std::string const & = "ALL") const override;

 private:
	std::string m_InttRawNodeName = "foo";

	TFile* m_file = nullptr;
	TTree* m_tree = nullptr;
	std::vector<InttHitJb>* m_hits = nullptr;

	struct MapStruct_s
	{
		bool hit;
		Long64_t hits;
	};
	typedef std::map<InttHitJb, MapStruct_s> MapType_t;
	MapType_t m_map;

};

#endif//INTT_PRODUCTION_JB_H
