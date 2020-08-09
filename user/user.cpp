#include "user.h"
using namespace std;

// id produs, cantitate produs in cos
// unordered_map<int,int> idCosProduse;

User::~User(){}

// Set-eri
void User::setNume(const string& nume)
{
  this->nume = nume;
}
void User::setPrenume(const string& prenume)
{
  this->prenume = prenume;
}
void User::setEmail(const string& email)
{
  this->email = email;
}
void User::setIdUser(int idUser)
{
  this->idUser = idUser;
}
void User::setDataNasterii(const string& dataN)
{
  this->dataNasterii = dataN;
}
void User::setDateFacturare(const Adresa& dateFacturare)
{
  this->dateFacturare = dateFacturare;
}
void User::setDateLivrare(const Adresa& dateLivrare)
{
  this->dateLivrare = dateLivrare;
}
// Get-eri
string& User::getNume()
{
  return this->nume;
}
string& User::getPrenume()
{
  return this->prenume;
}
string& User::getEmail()
{
  return this->email;
}
int User::getIdUser()
{
  return this->idUser;
}
string& User::getDataNasterii()
{
  return this->dataNasterii;
} 

Adresa& User::getDateFacturare()
{
  return this->dateFacturare;
}
Adresa& User::getDateLivrare()
{
  return this->dateLivrare;
}





