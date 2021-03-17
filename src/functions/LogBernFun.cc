#include <config.h>
#include "LogBernFun.h"
#include <util/nainf.h>

#include <cmath>

using std::vector;
using std::string;

#define x(par) (*args[0])
#define prob(par) (*args[1])

namespace Bernoulli{
// constructor function
// with 2 arguments the name of the logical node of the base class
// in a model file and the number of arguments
LogBernFun::LogBernFun() : ScalarFunction("logbern", 2)
{}

// checks if the parameter pi lies between 0 and 1
bool LogBernFun::checkParameterValue(vector<double const *> const &args) const
{
  return (x(par) == 0.0 || x(par) == 1.0
  	  && (prob(par) <= 1.0 && prob(par) >= 0.0));
}

// does the computation that the logical node is supposed to do
double LogBernFun::evaluate(vector<double const *> const &args) const
{
  double d = ( (x(par)==1) ? prob(par) : 1-prob(par) );
  return (d==0) ? JAGS_NEGINF : log(d);
}

}
