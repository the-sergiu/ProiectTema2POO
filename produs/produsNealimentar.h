#pragma once
#include "produs.h"

class ProdusNealimentar : public Produs
{
protected:
  string producator;
	int garantieAni;
	float pret;
public:
	
    ProdusNealimentar();
    ProdusNealimentar(const string&, int, const string&, const string&, float, int, int);

    void afisare();

    void setGarantieAni(int);
    void setPret(float);
    void setProducator(const string&);
    
    int getGarantieAni();
    float getPret();
    string& getProducator();

    bool operator == (const ProdusNealimentar&) const;


};

