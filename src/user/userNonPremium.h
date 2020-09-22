#pragma once
#include "user.h"

class UserNonPremium : public User
{
  protected:
    float costTransport;

  public:
  UserNonPremium();
  UserNonPremium(const string&, const string&, const string&, int, const string&, int, const string&, int, const string&, int, int, const string&, const string&, const string&, float);
  void vizualizareUser();

  void setCostTransport(int);
  int getCostTransport();
  
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserNonPremium, dateFacturare, dateLivrare, nume, prenume, email, UserId, costTransport)
};
