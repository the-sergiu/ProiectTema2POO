#pragma once
#include "user.h"

class UserNonPremium : public User
{
  protected:
    float costTransport;

  public:
  UserNonPremium(const string&, const string&, const string&, int, const string&, const Adresa&, const Adresa&, float);
  void setCostTransport(int);
  int getCostTransport();
  void vizualizareUser();



};