#include <module/Module.h> // include JAGS module base class
#include <distributions/DBern.h> // include Bernoulli distribution class
#include <functions/LogBernFun.h> // include Bernoulli functions class

using jags::Module;
using jags::Distribution;
using jags::Function;

namespace Bernoulli {// start defining the module namespace

  //Module class
  class BERNModule : public Module {
    public:
      BERNModule(); //constructor
      ~BERNModule(); //destructor
  };

  // Constructor function
  BERNModule::BERNModule() : Module("Bernoulli") {
  	insert(new DBern); //inherited function to load objects into JAGS
  	insert(new LogBernFun);
  }

  // Destructor function to delete objects when module is unloaded
  BERNModule::~BERNModule() {
  	std::vector<Distribution*> const &dvec = distributions();
  	for (unsigned int i = 0; i < dvec.size(); ++i) {
  	  delete dvec[i]; // delete all instantiated distribution objects
  	}
  	std::vector<Function*> const &fvec = functions();
  	for (unsigned int i = 0; i < fvec.size(); ++i) {
  	  delete fvec[i]; // delete all instantiated function objects
  	}
  }

} // end namespace definition

Bernoulli::BERNModule _Bernoulli_module;
