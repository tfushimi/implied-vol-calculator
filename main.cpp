#include <iostream>
#include "NewtonRaphson.hpp"
#include "BSCallClass.hpp"
#include "BlackScholesFormula.hpp"
#include "Bisection.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Black Schole model
    cout << BlackScholesCall(60, 65, 0.08, 0, 0.3, 0.25) << endl;
    cout << BlackScholesPut(60, 65, 0.08, 0, 0.3, 0.25) << endl;
    
    // variables
    double Expiry, Strike, Spot, r, d, Price;

    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter strike: ";
    cin >> Strike;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter d: ";
    cin >> d;
    cout << "Enter price: ";
    cin >> Price;
    
    // initial low and high guess
    double Low, High;
    cout << "Enter lower guess: ";
    cin >> Low;
    cout << "Enter higher guess: ";
    cin >> High;
    
    // tolerance
    double Tolerance;
    
    cout << "Enter tolerance: ";
    cin >> Tolerance;
    
    // option
    BSCall theCall(r, d, Expiry, Spot, Strike);
    
    // Bisection: implied volatility
    double vol = Bisection(Price, Low, High, Tolerance, theCall);
    
    // compute the calibrated price
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);
    cout << endl << "Implied Volatility (Bisection): " << vol << ", Price: " << PriceTwo << endl;

    // NewtonRaphson: implied volatility
    double Start;
    cout << "Enter start: ";
    cin >> Start;
    vol = NewtonRaphson<BSCall, &BSCall::operator(), &BSCall::Vega>(Price, Start, Tolerance, theCall);
    
    // compute the calibrated price
    double PriceThree = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);
    cout << endl << "Implied Volatility (NewtonRaphson): " << vol << ", Price: " << PriceThree << endl;
    
    return 0;
}
