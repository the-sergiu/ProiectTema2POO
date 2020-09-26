#pragma once
#include "produs.h"
#include <string>

class ProdusAlimentar : public Produs
{
protected:
    float leiPerKg;
    string taraOrigine;

public:
    // Constructori
    ProdusAlimentar();
    ProdusAlimentar(const string &, int, const string &, float, const string &, int);
    ProdusAlimentar(const ProdusAlimentar &);

    // Operator =
    const ProdusAlimentar &operator=(const ProdusAlimentar &);

    // Set
    void setLeiPerKg(float);
    void setTaraDeOrigine(const string &);

    // Get
    float getLeiPerKg();
    string &getTaraDeOrigine();

    // Metode Auxiliare
    void afisare();

    // Operatori
    bool operator==(const ProdusAlimentar &) const;
    bool operator<(const ProdusAlimentar &) const;
    bool operator>(const ProdusAlimentar &) const;

    // Administrative - NU MODIFICATI
    string getProdusType();
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusAlimentar, nume, cantitate, categorie, id, leiPerKg, taraOrigine)
};
