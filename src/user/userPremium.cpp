#include "userPremium.h"

using namespace std;

UserPremium::UserPremium() {}

UserPremium::UserPremium(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, int costAbonamentPremium, const unordered_map<int, int> &reduceri) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
  this->costAbonamentPremium = costAbonamentPremium;
  this->reduceri = reduceri;
}

UserPremium::UserPremium(const UserPremium &up) : User(up)
{
  this->reduceri = up.reduceri;
  this->costAbonamentPremium = up.costAbonamentPremium;
}

const UserPremium &UserPremium::operator=(const UserPremium &up)
{
  User::operator=(up);
  this->reduceri = up.reduceri;
  this->costAbonamentPremium = up.costAbonamentPremium;
  return *this;
}

void UserPremium::vizualizareUser()
{
  cout << endl
       << "-----------"
       << "USER PREMIUM: " << this->UserId << "----------" << endl;
  cout << "Nume: " << this->nume << endl;
  cout << "Prenume: " << this->prenume << endl;
  cout << "Email: " << this->email << endl;
  cout << "Date Facturare: " << this->dateFacturare;
  cout << "Date Livrare: " << this->dateLivrare;
  cout << "Cost abonament premium: " << this->costAbonamentPremium;
  cout << endl
       << "------------- LISTA REDUCERI -------------" << endl
       << endl;
  for (auto const &x : this->reduceri)
    cout << x.first << " - " << x.second << endl;
  cout << endl;
}

string UserPremium::getUserType()
{
  return "premium";
}

float UserPremium::getCostTransport()
{
  return 0;
}

unordered_map<int, int> &UserPremium::getMapReduceri()
{
  return reduceri;
}

void UserPremium::setReduceri(unordered_map<int, int> red)
{
  this->reduceri = red;
}

void UserPremium::setCostAbonamentPremium(int cap)
{
  this->costAbonamentPremium = cap;
}

int UserPremium::getCostAbonamentPremium()
{
  return this->costAbonamentPremium;
}

json UserPremium::toJSON()
{
  return json(*this);
}