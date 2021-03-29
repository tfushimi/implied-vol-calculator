#include "bsmodel/formulas.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>

using namespace std;
using namespace boost::math;

double callPrice(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double d1 = (log(Spot / Strike) + (r - d + 0.5 * Vol * Vol) * Expiry) / (Vol * sqrt(Expiry));
    double d2 = d1 - Vol * sqrt(Expiry);
    normal norm;
    return Spot * exp(-d*Expiry)* cdf(norm, d1) - Strike * exp(-r*Expiry) * cdf(norm, d2);
}

double putPrice(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double d1 = (log(Spot / Strike) + (r - d + 0.5 * Vol * Vol) * Expiry) / (Vol * sqrt(Expiry));
    double d2 = d1 - Vol * sqrt(Expiry);
    normal norm;
    return Strike * exp(-r*Expiry) * cdf(norm, -d2) - Spot * exp(-d*Expiry)* cdf(norm, -d1);
}

double callVega(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    normal norm;
    double d1 = (log(Spot / Strike) + (r - d + 0.5 * Vol * Vol) * Expiry) / (Vol * sqrt(Expiry));
    return Spot * exp(-d*Expiry) * sqrt(Expiry) * cdf(norm, d1);
}
