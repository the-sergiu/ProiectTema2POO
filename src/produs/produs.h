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
    virtual void afisare() = 0;
    virtual ~Produs() = 0;
    virtual string getProdusType() = 0;

    Produs();
    Produs(const string&, int, const string&, int);
    Produs(const Produs&p);

    bool checkCantitate(int);
    void scadeCantitate(int);
    void cresteCantitate(int);

    //SET-ERI
    void setCategorie(const string&);
    void setId(int);
    void setCantitate(int);
    void setNume(const string&);

    //GET-ERI
    string& getCategorie();
    int getCantitate();
    int getId();
    string& getNume();

    const Produs& operator = (const Produs&);

    virtual json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Produs, nume, cantitate, categorie, id)
};

