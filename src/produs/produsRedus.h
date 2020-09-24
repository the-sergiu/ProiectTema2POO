#pragma once
#include "produsNealimentar.h"

class ProdusRedus : virtual public ProdusNealimentar
{
protected:
	int procentReducere;
public:
    ProdusRedus();
    ProdusRedus(const string&, int, const string&, const string&, float, int, int, int);
    ProdusRedus(const ProdusRedus&);
    void afisare();

    float pretDupaReducere()const;
    
    // SET-eri
    void setProcentReducere(int);
    // GET-eri
    float getProcentReducere();

    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusRedus, nume, cantitate, categorie, id, producator, garantieAni, pret, procentReducere)
};
