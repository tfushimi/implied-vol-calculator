#include "bsmodel/formulas.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>

using namespace std;
using namespace boost::math;

double callPrice(double spot, double strike, double r, double d, double vol, double expiration) {
    double d1 = (log(spot / strike) + (r - d + 0.5 * vol * vol) * expiration) / (vol * sqrt(expiration));
    double d2 = d1 - vol * sqrt(expiration);
    normal norm;
    return spot * exp(-d*expiration)* cdf(norm, d1) - strike * exp(-r*expiration) * cdf(norm, d2);
}

double putPrice(double spot, double strike, double r, double d, double vol, double expiration) {
    double d1 = (log(spot / strike) + (r - d + 0.5 * vol * vol) * expiration) / (vol * sqrt(expiration));
    double d2 = d1 - vol * sqrt(expiration);
    normal norm;
    return strike * exp(-r*expiration) * cdf(norm, -d2) - spot * exp(-d*expiration)* cdf(norm, -d1);
}

double callVega(double spot, double strike, double r, double d, double vol, double expiration) {
    normal norm;
    double d1 = (log(spot / strike) + (r - d + 0.5 * vol * vol) * expiration) / (vol * sqrt(expiration));
    return spot * exp(-d*expiration) * sqrt(expiration) * cdf(norm, d1);
}
