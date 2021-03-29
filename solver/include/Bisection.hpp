#ifndef Bisection_hpp
#define Bisection_hpp
#include <cmath>

template<typename T>
double Bisection(double Target, double Low, double High, double Tolerance, T TheFunction)
{
    double x = 0.5 * (Low + High);
    double y = TheFunction(x);
    
    do {
        if (y < Target)
        {
            Low = x;
        }
        else
        {
            High = x;
        }
        x = 0.5 * (Low + High);
        y = TheFunction(x);
    } while ((std::fabs(y - Target) > Tolerance));
    return x;
}

#endif /* Bisection_hpp */
