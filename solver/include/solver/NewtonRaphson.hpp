#ifndef NewtonRaphson_hpp
#define NewtonRaphson_hpp
#include <cmath>

template<typename T, double (T::*Value)(double) const, double (T::*Derivative)(double) const>
double NewtonRaphson(double Target, double Start, double Tolerance, const T& TheObject)
{
    double y = (TheObject.*Value)(Start);
    double x = Start;
    
    while (std::fabs(y - Target) > Tolerance)
    {
        x += (Target - y) / (TheObject.*Derivative)(x);
        y = (TheObject.*Value)(x);
    }
    return x;
}
#endif 
