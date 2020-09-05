#pragma once
#include "produsNealimentar.h"


class ProdusRedus : virtual public ProdusNealimentar
{
protected:
	int procentReducere;
public:
    ProdusRedus();
    ProdusRedus(const string&, int, const string&, const string&, float, int, int, int);
    void afisare();

    float pretDupaReducere()const;
    
    // SET-eri
    void setProcentReducere(int);
    // GET-eri
    float getProcentReducere();
};
