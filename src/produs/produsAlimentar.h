#pragma once
#include "produs.h"
#include <string>

class ProdusAlimentar : public Produs
{
protected:
    float leiPerKg;
    string taraOrigine;
public:
    ProdusAlimentar();
    ProdusAlimentar(const string&, int, const string&, float, const string&, int);
    ProdusAlimentar(const ProdusAlimentar&);
    
    const ProdusAlimentar& operator = (const ProdusAlimentar&);
    
    void afisare();
    string getProdusType();

    void setLeiPerKg(float);
    void setTaraDeOrigine(const string&);

    float getLeiPerKg();
    string& getTaraDeOrigine();

  // FUNCTII FRIEND
  // In interafata, care sa verifice in clasa derivata
    bool operator == (const ProdusAlimentar&)const;
    bool operator < (const ProdusAlimentar&)const;
    bool operator > (const ProdusAlimentar&)const;


    json toJSON();

   NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusAlimentar, nume, cantitate, categorie, id, leiPerKg, taraOrigine)
};
