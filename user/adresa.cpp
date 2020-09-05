#include "adresa.h"

using namespace std;


Adresa::Adresa()
{
  strada = "";
  numar = 0;
  bloc = "";
  apartament = 0;
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


ostream& operator << (ostream& os, const Adresa& a)
{
  os <<"Judet: " << a.judet << ", Oras: " << a.oras <<", Strada: "<<a.strada<<", nr. "<<a.numar<<", bl. "<<a.bloc<<", ap. "<<a.apartament<<endl;
  return os;
}