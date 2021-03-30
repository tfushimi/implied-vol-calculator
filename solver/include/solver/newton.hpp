#ifndef newton_hpp
#define newton_hpp
#include <cmath>
#include <functional>

const int MAX_ITER = 20;

double newton(double target, double init, double tol, std::function<double(double)> f, std::function<double(double)> derivative) {
    double y = f(init), sol = init;
    int i = 0;

    while (std::fabs(y - target) > tol) {
        sol += (target - y) / derivative(sol);
        y = f(sol);
        if (i >= MAX_ITER) {
            throw std::runtime_error("failed to find a solution");
        }
        i++;
    }
    return sol;
}
#endif 
