#pragma once
#include "produs.h"

class ProdusNealimentar : public Produs
{
protected:
	int garantieAni;
	float pret;
public:
	
    ProdusNealimentar();
    ProdusNealimentar(const string&, const string&, int, int, int, float);

    void afisare();

    void setNume(const string&);
    void setCategorie(const string&);
    void setId(int);
    void setCantitate(int);
    void setGarantieAni(int);
    void setPret(float);
    
    string& getNume();
    string& getCategorie();
    int getId();
    int getCantitate();
    int getGarantieAni();
    float getPret();

    bool operator == (const ProdusNealimentar&) const;


};

