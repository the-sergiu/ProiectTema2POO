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
    ProdusNealimentar(const ProdusNealimentar& pn);

    void afisare();

    void setGarantieAni(int);
    void setPret(float);
    void setProducator(const string&);
    
    int getGarantieAni();
    float getPret();
    string& getProducator();

    bool operator == (const ProdusNealimentar&) const;

    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusNealimentar, nume, cantitate, categorie, id, producator, garantieAni, pret)

};

