#include "user.h"
using namespace std;

User::~User() {}

User::User() {}

User::User(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int UserId, const string &nume, const string &prenume, const string &email) : dateFacturare(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf), dateLivrare(judetl, localitatel, stradal, nr_stradal, blocl, apartamentl)
{
  this->UserId = UserId;
  this->nume = nume;
  this->prenume = prenume;
  this->email = email;
}

User::User(const User &u)
{
  this->dateFacturare = u.dateFacturare;
  this->dateLivrare = u.dateLivrare;
  this->nume = u.nume;
  this->prenume = u.prenume;
  this->email = u.email;
  this->UserId = u.UserId;
}

const User &User::operator=(const User &u)
{
  this->dateFacturare = u.dateFacturare;
  this->dateLivrare = u.dateLivrare;
  this->nume = u.nume;
  this->prenume = u.prenume;
  this->email = u.email;
  this->UserId = u.UserId;

  return *this;
}

// Set-eri
void User::setNume(const string &nume)
{
  this->nume = nume;
}
void User::setPrenume(const string &prenume)
{
  this->prenume = prenume;
}
void User::setEmail(const string &email)
{
  this->email = email;
}
void User::setIdUser(int idUser)
{
  this->UserId = idUser;
}
void User::setDateFacturare(const Adresa &dateFacturare)
{
  this->dateFacturare = dateFacturare;
}
void User::setDateLivrare(const Adresa &dateLivrare)
{
  this->dateLivrare = dateLivrare;
}
// Get-eri
string &User::getNume()
{
  return this->nume;
}
string &User::getPrenume()
{
  return this->prenume;
}
string &User::getEmail()
{
  return this->email;
}
int User::getIdUser() const
{
  return this->UserId;
}

Adresa &User::getDateFacturare()
{
  return this->dateFacturare;
}
Adresa &User::getDateLivrare()
{
  return this->dateLivrare;
}

json User::toJSON()
{
  return json(*this);
}
