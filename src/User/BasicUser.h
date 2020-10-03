#pragma once
#include "User.h"

class BasicUser : public User
{
protected:
  float costTransport;

public:
  // Constructori
  BasicUser();
  BasicUser(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &, float);
  BasicUser(const BasicUser &);

  // Operator =
  BasicUser &operator=(const BasicUser &);

  // Set
  void setTransportCost(int);

  // Get
  float getTransportCost();
  string getUserType();

  // Metode Auxiliare
  void displayUser();

  // Administrativ - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(BasicUser, billingData, deliveryData, lastName, firstName, email, UserID, costTransport)
};
