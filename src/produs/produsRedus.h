#pragma once
#include "produsNealimentar.h"

class ProdusRedus : virtual public ProdusNealimentar
{
protected:
    int procentReducere;

public:
    // Constructori
    ProdusRedus();
    ProdusRedus(const string &, int, const string &, const string &, float, int, int, int);
    ProdusRedus(const ProdusRedus &);

    // Operator =
    const ProdusRedus &operator=(const ProdusRedus &);

    // Set
    void setProcentReducere(int);
    // Get
    float getProcentReducere();

    // Metode Auxiliare
    void afisare();
    float pretDupaReducere() const;

    // Administrative - NU MODIFICATI
    string getProdusType();
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusRedus, nume, cantitate, categorie, id, producator, garantieAni, pret, procentReducere)
};
