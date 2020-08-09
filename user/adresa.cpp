#include "adresa.h"

using namespace std;


Adresa::Adresa()
{
  strada = "";
  numar = 0;
  bloc = "";
  apartament = 0;
}

Adresa::Adresa(const string& str, int nr, const string& bl, int ap)
{
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

ostream& operator << (ostream& os, Adresa& a)
{
  os <<"Strada: "<<a.strada<<", nr. "<<a.numar<<", bl. "<<a.bloc<<", ap. "<<a.apartament<<endl;
  return os;
}