#pragma once
#include <iostream>
#include <string>
using namespace std;

#define placeHolder "?"
//id - 1 - alim/ProdusNealimentar; 2 - categ; 3 - indexul produsului


class Produs
{
protected:
    string nume;
    int cantitate = 0;
    string categorie;
    int id;  
public:
    virtual void afisare() = 0;
    virtual ~Produs() = 0;

    // TODO
    bool checkCantitate(int);
    void scadeCantitate(int);
    void cresteCantitate(int);
    
};

