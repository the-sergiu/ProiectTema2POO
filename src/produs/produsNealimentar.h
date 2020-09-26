#pragma once
#include "produs.h"

class ProdusNealimentar : public Produs
{
protected:
  string producator;
  int garantieAni;
  float pret;

public:
  // Constructori
  ProdusNealimentar();
  ProdusNealimentar(const string &, int, const string &, const string &, float, int, int);
  ProdusNealimentar(const ProdusNealimentar &pn);

  // Operator =
  const ProdusNealimentar &operator=(const ProdusNealimentar &);

  // Set
  void setGarantieAni(int);
  void setPret(float);
  void setProducator(const string &);

  // Get
  int getGarantieAni();
  float getPret();
  string &getProducator();

  // Metode Auxiliare
  void afisare();
  string getProdusType();

  // Operator ==
  bool operator==(const ProdusNealimentar &) const;

  // Administrative - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusNealimentar, nume, cantitate, categorie, id, producator, garantieAni, pret)
};
