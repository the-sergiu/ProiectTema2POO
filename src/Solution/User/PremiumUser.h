#pragma once
#include "User.h"
#include <string>

using namespace std;

class PremiumUser : public User
{
protected:
  map<int, int> discounts; // idProdus-discountPercentage
  int premiumSubscriptionCost;

public:
  // Constructori
  PremiumUser();
  PremiumUser(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &, int, const map<int, int> &);
  PremiumUser(const PremiumUser &);

  // Operator =
  const PremiumUser &operator=(const PremiumUser &);

  // Set
  void setDiscounts(map<int, int> red);
  void setPremiumSubscriptionCost(int cap);

  // Get
  float getTransportCost();
  map<int, int> &getDiscounts();
  int getPremiumSubscriptionCost();
  string getUserType();

  // Metode Auxiliare
  void displayUser();

  // Administrative - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(PremiumUser, billingData, deliveryData, lastName, firstName, email, UserID, premiumSubscriptionCost, discounts)
};