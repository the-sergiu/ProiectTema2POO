#pragma once
#include "produs.h"
#include <string>

class ProdusAlimentar : public Produs
{
protected:
    float leiPerKg;
    string dataExp;
    string taraOrigine;
public:
    ProdusAlimentar();
    ProdusAlimentar(const string&,const string&, int, int, float, const string&, const string&);
    void afisare();

    void setCategorie(const string&);
    void setId(int);
    void setCantitate(int);
    void setLeiPerKg(float);
    void setDataExp(const string&);
    void setTaraDeOrigine(const string&);
    void setNume(const string&);

    
    string& getCategorie();
    int getId();
    int getCantitate();
    float getLeiPerKg();
    string& getDataExp();
    string& getTaraDeOrigine();
    string& getNume();

  // FUNCTII FRIEND
  // In interafata, care sa verifice in clasa derivata
    bool operator == (const ProdusAlimentar&)const;
    bool operator < (const ProdusAlimentar&)const;
    bool operator > (const ProdusAlimentar&)const;

};
