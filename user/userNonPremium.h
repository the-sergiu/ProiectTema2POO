#pragma once
#include "user.h"

class UserNonPremium : public User
{
  protected:
    float costTransport;

  public:
  UserNonPremium(const string&, const string&, const string&, int, const string&, int, const string&, int, const string&, int, int, const string&, const string&, const string&, float);
  void setCostTransport(int);
  int getCostTransport();
  void vizualizareUser();



};
