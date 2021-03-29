#ifndef BlackScholesFormula_hpp
#define BlackScholesFormula_hpp

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);
double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry);
double BlackScholesCallVega(double Spot, double Strike, double r, double d, double Vol, double Expiry);
#endif