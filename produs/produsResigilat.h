#pragma once
#include "produsRedus.h"
#include "produsReturnat.h"
class ProdusResigilat : public ProdusRedus, public ProdusReturnat
{
private:
private:
    int procentUzura;
public:
    ProdusResigilat();
    ProdusResigilat(const string&, int, const string&, const string&, float, int, int, const string&, int, int);
    
    void afisare();

    //SET-ERI
    void setProcentUzura(int);
    
    //GET-ERI
    float getProcentUzura();


};

