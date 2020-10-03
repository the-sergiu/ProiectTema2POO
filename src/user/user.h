#pragma once
#include <string>
#include <unordered_map>

#include "adresa.h"
#include "../produs/produsResigilat.h"
#include "../produs/FoodProduct.h"

using namespace std;

class User
{
protected:
  Adresa dateFacturare;
  Adresa dateLivrare;
  string nume;
  string prenume;
  string email;
  int UserId;

public:
  // Virtuale
  virtual string getUserType() = 0;
  virtual float getCostTransport() = 0;
  virtual void vizualizareUser() = 0;
  virtual ~User() = 0;

  // Constructori
  User();
  User(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &);
  User(const User &);

  // Operator =
  const User &operator=(const User &);

  // Set
  void setNume(const string &);
  void setPrenume(const string &);
  void setEmail(const string &);
  void setIdUser(int);
  void setDateFacturare(const Adresa &);
  void setDateLivrare(const Adresa &);

  // Get
  string &getNume();
  string &getPrenume();
  string &getEmail();
  int getIdUser() const;
  Adresa &getDateFacturare();
  Adresa &getDateLivrare();

  // Administrativ - NU MODIFICATI
  virtual json toJSON();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, dateFacturare, dateLivrare, nume, prenume, email, UserId)
};
