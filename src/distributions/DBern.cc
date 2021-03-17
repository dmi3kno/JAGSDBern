#include <config.h> // syste, config file created by Autoconf 
		     //and defined in configure.ac
#include "DBern.h" // header file containing class prototype
#include <rng/RNG.h> // provides random functions
#include <util/nainf.h> // provides na and inf functions etc

#include <cmath> // library for standard math operations

using std::vector; //vector is used in code
using std::min; //min is used in code
using std::max; //max is used in code

#define PROB(par) (*par[0]) // makes code more readable

namespace Bernoulli { //module namespace

// The constructor function:
// also calls the constructor of the base class
// the base class constructor takes as input arguments:
// 1- the name of the distribution node, as used in the BUGS code
// 2- the number of arguments of that node
// 3- distribution type

DBern::DBern() : ScalarDist("dbern2", 1, DIST_PROPORTION)
{}

// other functions
// this function checks in the probability parameter of the Bernoulli distr lies between 0,1
// returning false if it doesnt
bool DBern::checkParameterValue(vector<double const *> const &parameters) const
{
	return (PROB(parameters) >= 0.0 && PROB(parameters) <= 1.0);
}

// This function calcuates the log(density) at a given value (data point)
// for fiven parameter value (in this case for a given probability pi)
double DBern::logDensity(double x, PDFType type, 
	vector<double const *> const &parameters,
	double const *lbound, double const *ubound) const
{
    double d = (x ? PROB(parameters) : 1 - PROB(parameters));
    return (d == 0) ? JAGS_NEGINF : log(d);
}
  
// this function is used for drawing random samples for given parameter values
// in this case for a give probability pi
double DBern::randomSample(vector<double const *> const &parameters,
	double const *lbound, double const *ubound,
	RNG *rng) const
{
    return (rng->uniform() < PROB(parameters)) ? 1 : 0;
}

// this function returns a typical value for tthis dstri
// in this case a Bernoulli distri with a gjven probability pi
double DBern::typicalValue(vector<double const *> const &parameters,
	double const *lbound, double const *ubound) const
{
    return (PROB(parameters)>0.5) ? 1 : 0;
}
	
// this function redefine is needed. As Bernouuli distr is discrete
bool DBern::isDiscreteValued(vector<bool> const &mask) const
{
    return true;
}

} // end of namespace definition


