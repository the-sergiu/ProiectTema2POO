#include "adresa.h"

using namespace std;


Adresa::Adresa()
{
  strada = "";
  numar = 0;
  bloc = "";
  apartament = 0;
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


ostream& operator << (ostream& os, const Adresa& a)
{
  os <<"Judet: " << a.judet << ", Localitate: " << a.localitate <<", Strada: "<<a.strada<<", nr. "<<a.numar<<", bl. "<<a.bloc<<", ap. "<<a.apartament<<endl;
  return os;
}

json Adresa::toJSON(){
  return json(*this);
}