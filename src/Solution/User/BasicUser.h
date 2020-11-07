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

  /*
   * @param seteaza TransportCost (costul transportului)
   */
  void setTransportCost(int);
  /*
   * @return campul Transport Cost (costul transportului)
   */
  float getTransportCost();
  /*
   * @return UserType (string aferent tipului clasei - nu este un camp)
   */
  string getUserType();
  /*
   *     ADMINISTRATIV - NU MODIFICATI
   */
  json toJSON();
  void displayUser();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(BasicUser, billingData, deliveryData, lastName, firstName, email, UserID, costTransport)
};
