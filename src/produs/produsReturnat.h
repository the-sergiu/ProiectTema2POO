#pragma once
#include "produsNealimentar.h"

class ProdusReturnat : virtual public ProdusNealimentar
{
protected:
    string motiv;
public:
    ProdusReturnat();
    ProdusReturnat(const string&, int, const string&, const string&, float, int, const string&, int);
    ProdusReturnat(const ProdusReturnat &);


    void afisare();
    string getProdusType();


    //SET-ERI
    string& getMotiv();
    
    //GET-ERI
    void setMotiv(string&);

    const ProdusReturnat& operator = (const ProdusReturnat&);

    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusReturnat, nume, cantitate, categorie, id, producator, garantieAni, pret, motiv)
};

