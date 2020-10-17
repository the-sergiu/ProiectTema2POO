#pragma once
#include <string>
#include <map>

#include "Address.h"
#include "../Product/ResealedProduct.h"
#include "../Product/FoodProduct.h"

using namespace std;

class User
{
protected:
  Address billingData;
  Address deliveryData;
  string lastName;
  string firstName;
  string email;
  int UserID;

public:
  // Virtuale
  virtual string getUserType() = 0;
  virtual float getTransportCost() = 0;
  virtual void displayUser() = 0;
  virtual ~User() = 0;

  // Constructori
  User();
  User(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &);
  User(const User &);

  // Operator =
  const User &operator=(const User &);

  // Set
  void setLastName(const string &lastName);
  void setFirstName(const string &firstName);
  void setEmail(const string &);
  void setUserID(int);
  void setBillingData(const Address &billingData);
  void setDeliveryData(const Address &deliveryData);

  // Get
  string &getLastName();
  string &getFirstName();
  string &getEmail();
  int getUserID() const;
  Address &getBillingData();
  Address &getDeliveryData();

  // Administrativ - NU MODIFICATI
  virtual json toJSON();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, billingData, deliveryData, lastName, firstName, email, UserID)
};
