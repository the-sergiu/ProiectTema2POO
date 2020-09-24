#pragma once
#include "produsRedus.h"
#include "produsReturnat.h"

class ProdusResigilat : public ProdusRedus, public ProdusReturnat
{
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

    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusResigilat, nume, cantitate, categorie, id, producator, garantieAni, pret, motiv, procentReducere)
};

