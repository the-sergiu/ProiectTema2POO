#pragma once
#include <iostream>
#include <string>
#include "../json.hpp"

using namespace std;
using json = nlohmann::json;

#define placeHolder "?"

class Produs
{
protected:
    string nume;
    int cantitate;
    string categorie;
    int id;

public:
    // Virtuale
    virtual void afisare() = 0;
    virtual ~Produs() = 0;
    virtual string getProdusType() = 0;

    // Constructori
    Produs();
    Produs(const string &, int, const string &, int);
    Produs(const Produs &p);

    // Operator =
    const Produs &operator=(const Produs &);

    // Set
    void setCategorie(const string &);
    void setId(int);
    void setCantitate(int);
    void setNume(const string &);

    // Get
    string &getCategorie();
    int getCantitate();
    int getId();
    string &getNume();

    // Metode Auxiliare
    bool checkCantitate(int);
    void scadeCantitate(int);
    void cresteCantitate(int);

    // Administrative - NU MODIFICATI
    virtual json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Produs, nume, cantitate, categorie, id)
};
