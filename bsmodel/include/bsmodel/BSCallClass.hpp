#ifndef BSCallClass_hpp
#define BSCallClass_hpp

class BSCall
{
public:
    BSCall(double r_, double d_, double T_, double Spot_, double Strike_);
    double operator()(double Vol) const;
    double Vega(double Vol) const;
private:
    double r, d, T, Spot, Strike, Expiry;
};
#endif
