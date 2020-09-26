#pragma once
#include "produsNealimentar.h"

class ProdusReturnat : virtual public ProdusNealimentar
{
protected:
    string motiv;

public:
    // Constructori
    ProdusReturnat();
    ProdusReturnat(const string &, int, const string &, const string &, float, int, const string &, int);
    ProdusReturnat(const ProdusReturnat &);

    // Operator =
    const ProdusReturnat &operator=(const ProdusReturnat &);

    // Set
    string &getMotiv();

    // Get
    void setMotiv(string &);

    // Metode Auxiliare
    void afisare();
    string getProdusType();

    // Administrativ - NU MODIFICATI
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusReturnat, nume, cantitate, categorie, id, producator, garantieAni, pret, motiv)
};
