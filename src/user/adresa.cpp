#include "adresa.h"

using namespace std;


Adresa::Adresa()
{
  strada = "";
  numar = 0;
  bloc = "";
  apartament = 0;
}


Adresa::Adresa(const Adresa& adresa) {
  this->apartament = adresa.apartament;
  this->bloc = adresa.bloc;
  this->judet = adresa.judet;
  this->numar = adresa.numar;
  this->strada = adresa.strada;
  this->localitate = adresa.localitate;
}

Adresa::Adresa(const string& jud, const string& loc, const string& str, int nr, const string& bl, int ap)
{
  judet = jud;
  localitate = loc;
  strada = str;
  numar = nr;
  bloc = bl;
  apartament = ap;
}

Adresa& Adresa::operator=(const Adresa& adr)
{
  this->judet = adr.judet;
  this->localitate = adr.localitate;
  this->strada = adr.strada;
  this->numar = adr.numar;
  this->apartament = adr.apartament;
  this->bloc = adr.bloc;

  return *this;
}

void Adresa::setStrada(const string& str)
{
  strada = str;
}

void Adresa::setNumar(int nr)
{
  numar = nr;
}

void Adresa::setBloc(const string& bl)
{
  bloc = bl;
}

void Adresa::setApartament(int ap)
{
  apartament = ap;
}

void Adresa::setJudet(const string& jud)
{
  judet = jud;
}

void Adresa::setLocalitate(const string& loc)
{
  localitate = loc;
}

string& Adresa::getStrada()
{
  return this->strada;
}

int Adresa::getNumar()
{
  return this->numar;
}
string& Adresa::getBloc()
{
  return this->bloc;
}

int Adresa::getApartament()
{
  return this->apartament;
}

string& Adresa::getJudet()
{
  return judet;
}

string& Adresa::getLocalitate()
{
  return localitate;
}


bool Adresa::operator==(const Adresa& adresa) {
  if (this->judet != adresa.judet) return false;
  if (this->localitate != adresa.localitate) return false;
  if (this->strada != adresa.strada) return false;
  if (this->numar != adresa.numar) return false;
  if (this->bloc != adresa.bloc) return false;
  if (this->apartament != adresa.apartament) return false;

  return true;
}

bool Adresa::operator!=(const Adresa &adresa) {
  return !(*this == adresa);
}

ostream& operator << (ostream& os, const Adresa& a)
{
  os <<"Judet: " << a.judet << ", Localitate: " << a.localitate <<", Strada: "<<a.strada<<", nr. "<<a.numar<<", bl. "<<a.bloc<<", ap. "<<a.apartament<<endl;
  return os;
}

json Adresa::toJSON(){
  return json(*this);
}