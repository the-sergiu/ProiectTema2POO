#pragma once
#include "produsNealimentar.h"


class ProdusRedus : virtual public ProdusNealimentar
{
protected:
	float procentReducere;
public:
    ProdusRedus();
    ProdusRedus(const string&, const string&, int, int, int, float, float);
    void afisare();

    float pretDupaReducere()const;
    
    // SET-eri
    void setProcentReducere(int);
    // GET-eri
    float getProcentReducere();
};

