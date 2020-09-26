#include "produs.h"
using namespace std;

Produs::~Produs(){}


bool Produs::checkCantitate(int cantitateCeruta)
{
  cout<<endl<<"Cantitatea produsului este "<<this->cantitate<<endl;
  if (this->cantitate >= cantitateCeruta)
    return true;
  else return false;
}

Produs::Produs(const string& categorie, int id, const string& nume, int cantitate)
{
  this->categorie = categorie;
  this->id = id;
  this->nume = nume;
  this->cantitate = cantitate;
}

Produs::Produs(const Produs &p)
{
  this->categorie = p.categorie;
  this->id = p.id;
  this->nume = p.nume;
  this->cantitate = p.cantitate;
}

Produs::Produs()
{
  this->categorie = placeHolder;
  this->id = -1;
  this->nume = placeHolder;
  this->cantitate = -1;
}

void Produs::scadeCantitate(int cantitateCeruta)
{
  this->cantitate -= cantitateCeruta;
}

void Produs::cresteCantitate(int cantitateCeruta)
{
  this->cantitate += cantitateCeruta;
}
  
void Produs::setCategorie(const string& categorie)
{
  this->categorie = categorie;
}

void Produs::setId(int id)
{
  this->id = id;
}

void Produs::setCantitate(int cantitate)
{
  this->cantitate = cantitate;
}

void Produs::setNume(const string& nume)
{
  this->nume = nume;
}

string& Produs::getCategorie()
{
  return this->categorie;
}

int Produs::getCantitate()
{
  return this->cantitate;
}

int Produs::getId()
{
  return this->id;
}

string& Produs::getNume()
{
  return this->nume;
}

const Produs& Produs::operator=(const Produs& a){
  this->nume = a.nume;
  this->categorie = a.categorie;
  this->id = a.id;
  this->cantitate = a.cantitate;

  return *this;
}

json Produs::toJSON(){
  return json(*this);
}
