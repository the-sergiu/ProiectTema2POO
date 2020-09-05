 #pragma once
#include "produsNealimentar.h"
class ProdusReturnat : virtual public ProdusNealimentar
{
protected:
    string motiv;
public:
    ProdusReturnat();
    ProdusReturnat(const string&, int, const string&, const string&, float, int, const string&, int);
    void afisare();


    //SET-ERI
    string& getMotiv();
    
    //GET-ERI
    void setMotiv(string&);

};

