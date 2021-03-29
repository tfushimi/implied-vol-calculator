#ifndef bisection_hpp
#define bisection_hpp
#include <cmath>

template<typename T>
double bisection(double target, double lower, double upper, double tol, T f) {
    double sol = 0.5 * (lower + upper);
    double y = f(sol);
    
    while ((std::fabs(y - target) > tol)) {
        if (y < target)
        {
            lower = sol;
        }
        else
        {
            upper = sol;
        }
        sol = 0.5 * (lower + upper);
        y = f(sol);
    } ;
    return sol;
}

#endif
