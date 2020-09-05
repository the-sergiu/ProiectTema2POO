#pragma once
#include <iostream>
#include <string>
using namespace std;

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

    Produs();
    Produs(const string&, int, const string&, int);
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
    
};

