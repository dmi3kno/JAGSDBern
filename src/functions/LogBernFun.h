#ifndef BERN_FUNC_H_
#define BERN_FUNC_H_

#include <function/ScalarFunction.h>

using jags::ScalarFunction;

namespace Bernoulli { //module namespace

class LogBernFun : public ScalarFunction
{
  public:
    LogBernFun(); // the constructor
    
    // the two necessary functions that have to be implemented
    bool checkParameterValue(std::vector<double const *> const &args) const;
    double evaluate(std::vector<double const *> const &args) const;
};

}

#endif /* BERN_FUNC_H_ */
