#pragma once
#include "user.h"

class UserNonPremium : public User
{
protected:
  float costTransport;

public:
  // Constructori
  UserNonPremium();
  UserNonPremium(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &, float);
  UserNonPremium(const UserNonPremium &);

  // Operator =
  UserNonPremium &operator=(const UserNonPremium &);

  // Set
  void setCostTransport(int);

  // Get
  float getCostTransport();
  string getUserType();

  // Metode Auxiliare
  void vizualizareUser();

  // Administrativ - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserNonPremium, dateFacturare, dateLivrare, nume, prenume, email, UserId, costTransport)
};
