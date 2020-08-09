#pragma once
#include "produsNealimentar.h"
class ProdusReturnat : virtual public ProdusNealimentar
{
protected:
    string motiv;
public:
    ProdusReturnat();
    ProdusReturnat(const string&, const string&, const string&, int, int, int, float);
    void afisare();


    //SET-ERI
    string& getMotiv();
    
    //GET-ERI
    void setMotiv(string&);

};

