#include <module/Module.h> // include JAGS module base class
#include <distributions/DBern.h> // include Bernoulli distribution class

using jags::Module;
using jags::Distribution;

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
  }

  // Destructor function
  BERNModule::~BERNModule() {
  	std::vector<Distribution*> const &dvec = distributions();
  	for (unsigned int i = 0; i < dvec.size(); ++i) {
  	  delete dvec[i]; // delete all instantiated distribution objects
  	}
  }

} // end namespace definition

Bernoulli::BERNModule _Bernoulli_module;
