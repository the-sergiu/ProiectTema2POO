#include "BasicUser.h"

using namespace std;

BasicUser::BasicUser() {}

BasicUser::BasicUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, float costTransport) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
  this->costTransport = costTransport;
}

BasicUser::BasicUser(const BasicUser &unp) : User(unp)
{
  this->costTransport = unp.costTransport;
}

BasicUser &BasicUser::operator=(const BasicUser &unp)
{
  User ::operator=(unp);
  this->costTransport = unp.costTransport;
  return *this;
}

void BasicUser::setTransportCost(int cost)
{
  costTransport = cost;
}

float BasicUser::getTransportCost()
{
  return this->costTransport;
}

void BasicUser::displayUser()
{
  cout << "----------"
       << "USER NON-PREMIUM: " << this->UserID << "----------" << endl;
  cout << "Nume: " << this->lastName << endl;
  cout << "Prenume: " << this->firstName << endl;
  cout << "Email: " << this->email << endl;
  cout << "Date Facturare: " << this->billingData;
  cout << "Date Livrare: " << this->deliveryData;
  cout << "Cost transport standard: " << this->costTransport << endl
       << endl;
}

string BasicUser::getUserType()
{
  return "nonpremium";
}

json BasicUser::toJSON()
{
  return json(*this);
}
