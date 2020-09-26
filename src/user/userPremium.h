#pragma once
#include "user.h"
#include <string>

using namespace std;

class UserPremium : public User
{
protected:
  unordered_map<int, int> reduceri; // idProdus-procentReducere
  int costAbonamentPremium;

public:
  // Constructori
  UserPremium();
  UserPremium(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &, int, const unordered_map<int, int> &);
  UserPremium(const UserPremium &);

  // Operator =
  const UserPremium &operator=(const UserPremium &);

  // Set
  void setReduceri(unordered_map<int, int>);
  void setCostAbonamentPremium(int cap);

  // Get
  float getCostTransport();
  unordered_map<int, int> &getMapReduceri();
  int getCostAbonamentPremium();
  string getUserType();

  // Metode Auxiliare
  void vizualizareUser();

  // Administrative - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserPremium, dateFacturare, dateLivrare, nume, prenume, email, UserId, costAbonamentPremium, reduceri)
};