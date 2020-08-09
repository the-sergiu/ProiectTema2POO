#pragma once
#include "produsRedus.h"
#include "produsReturnat.h"
class ProdusResigilat : public ProdusRedus, public ProdusReturnat
{
private:
private:
    float procentUzura;
public:
    ProdusResigilat();
    ProdusResigilat(const string&, const string&, const string&, int, int, int, float, float, float);
    
    void afisare();

    //SET-ERI
    void setProcentUzura(int);
    
    //GET-ERI
    float getProcentUzura();


};

