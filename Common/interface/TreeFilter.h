#ifndef TreeFilter_h
#define TreeFilter_h

#include "NtuTool/Common/interface/TreeWrapper.h"
#include <string>
#include <set>

class TFile;
class TDirectory;

class TreeFilter: public virtual TreeWrapper {

 public:

  TreeFilter();
  virtual ~TreeFilter();

  virtual void dropBranch( const std::string& name );
  virtual void initWSkim( TFile* file );
  virtual void fillSkim();
  virtual void closeSkim();

 protected:

  TTree* filterTree;

 private:

  DataHandlerManager* fhManager;

  TreeFilter( const TreeFilter& t );
  TreeFilter& operator=( const TreeFilter& t );

  TDirectory* treeDir;
  std::set<std::string> skimDrop;

};


#endif
