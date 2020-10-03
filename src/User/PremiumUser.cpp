#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser() {}

PremiumUser::PremiumUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf,
                         const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl,
                         int id, const string &nume, const string &prenume, const string &email, int premiumSubscriptionCost, const unordered_map<int, int> &discounts)
            : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
  this->premiumSubscriptionCost = premiumSubscriptionCost;
  this->discounts = discounts;
}

PremiumUser::PremiumUser(const PremiumUser &up) : User(up)
{
  this->discounts = up.discounts;
  this->premiumSubscriptionCost = up.premiumSubscriptionCost;
}

const PremiumUser &PremiumUser::operator=(const PremiumUser &up)
{
  User::operator=(up);
  this->discounts = up.discounts;
  this->premiumSubscriptionCost = up.premiumSubscriptionCost;
  return *this;
}

void PremiumUser::displayUser()
{
  cout << endl
       << "-----------"
       << "USER PREMIUM: " << this->UserID << "----------" << endl;
  cout << "Nume: " << this->lastName << endl;
  cout << "Prenume: " << this->firstName << endl;
  cout << "Email: " << this->email << endl;
  cout << "Date Facturare: " << this->billingData;
  cout << "Date Livrare: " << this->deliveryData;
  cout << "Cost abonament premium: " << this->premiumSubscriptionCost;
  cout << endl
       << "------------- LISTA REDUCERI -------------" << endl
       << endl;
  for (auto const &x : this->discounts)
    cout << x.first << " - " << x.second << endl;
  cout << endl;
}

string PremiumUser::getUserType()
{
  return "premium";
}

float PremiumUser::getTransportCost()
{
  return 0;
}

unordered_map<int, int> &PremiumUser::getDiscounts()
{
  return discounts;
}

void PremiumUser::setDiscounts(unordered_map<int, int> red)
{
  this->discounts = red;
}

void PremiumUser::setPremiumSubscriptionCost(int cap)
{
  this->premiumSubscriptionCost = cap;
}

int PremiumUser::getPremiumSubscriptionCost()
{
  return this->premiumSubscriptionCost;
}

json PremiumUser::toJSON()
{
  return json(*this);
}