#ifndef formulas_hpp
#define formulas_hpp

double callPrice(double spot, double strike, double r, double d, double vol, double expiration);
double putPrice(double spot, double strike, double r, double d, double vol, double expiration);
double callVega(double spot, double strike, double r, double d, double vol, double expiration);

#endif