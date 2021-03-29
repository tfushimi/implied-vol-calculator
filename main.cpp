#include <iostream>
#include "solver/newton.hpp"
#include "bsmodel/formulas.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // variables
    double expiration, strike, spot, r, d, price;

    cout << "Enter expiration: ";
    cin >> expiration;
    cout << "Enter strike: ";
    cin >> strike;
    cout << "Enter spot: ";
    cin >> spot;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter d: ";
    cin >> d;
    cout << "Enter price: ";
    cin >> price;
    
    // tolerance
    double tolerance;
    
    cout << "Enter tolerance: ";
    cin >> tolerance;

    // initial value
    double init;
    cout << "Enter init: ";
    cin >> init;
   
    // find implied volatility
    auto bsVol = [spot, strike, r, d, expiration](double vol) { return callPrice(spot, strike, r, d, vol, expiration); };
    auto vega = [spot, strike, r, d, expiration](double vol) { return callVega(spot, strike, r, d, vol, expiration); };
    double vol = newton(price, init, tolerance, bsVol, vega);

    // compute the bs price using the solution volatility
    double bsPrice = callPrice(spot, strike, r, d, vol, expiration);
    cout << endl << "Implied Volatility (NewtonRaphson): " << vol << ", Price: " << bsPrice << endl;
    
    return 0;
}
