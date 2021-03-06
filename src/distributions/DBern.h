#ifndef DBERN_H_
#define DBERN_H_
#include <distribution/ScalarDist.h> // JAGS scalar distributions base class

using jags::ScalarDist;
using jags::PDFType;
using jags::RNG;

namespace Bernoulli {

class DBern : public ScalarDist {
  public:
    DBern(); // call constructor
    double logDensity(double x, PDFType type, 
                      std::vector<double const *> const &parameters,
                      double const *lower, double const *upper) const;
    double randomSample(std::vector<double const *> const &parameters,
                      double const *lower, double const *upper,
                      RNG *rng) const;
    double typicalValue(std::vector<double const *> const &parameters,
    			double const *lower, double const *upper) const;
    /** Checks that pi lies in the open interval (0,1) **/
    bool checkParameterValue(std::vector<double const *> const &parameters) const;
    /** Bernoulli distribution is discrete valued**/
    bool isDiscreteValued(std::vector<bool> const &mask) const;
};

}
#endif /* DBERN_H_ */
