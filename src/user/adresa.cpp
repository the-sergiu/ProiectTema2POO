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
  this->oras = adresa.oras;
  this->strada = adresa.strada;
}

Adresa::Adresa(const string& jud, const string& Oras, const string& str, int nr, const string& bl, int ap)
{
  judet = jud;
  oras = Oras;
  strada = str;
  numar = nr;
  bloc = bl;
  apartament = ap;
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

void Adresa::setOras(const string& Oras)
{
  oras = Oras;
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

string& Adresa::getOras()
{
  return oras;
}


bool Adresa::operator==(const Adresa& adresa) {
  if (this->judet != adresa.judet) return false;
  if (this->oras != adresa.oras) return false;
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
  os <<"Judet: " << a.judet << ", Oras: " << a.oras <<", Strada: "<<a.strada<<", nr. "<<a.numar<<", bl. "<<a.bloc<<", ap. "<<a.apartament<<endl;
  return os;
}

json Adresa::toJSON(){
  return json(*this);
}