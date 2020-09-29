#include "cosProduse.h"

CosProduse::CosProduse()
{
  this->metodaPlata = "-";
}

CosProduse::CosProduse(const string& metodaPlata)
{
  this->metodaPlata = metodaPlata;
}

string& CosProduse::getMetodaPlata()
{
  return this->metodaPlata;
}

void CosProduse::setMetodaPlata(const string& metodaPlata)
{
  this->metodaPlata = metodaPlata;
}

void CosProduse::addProdus(int id, int cantitate)
{
  produse[id] = cantitate;
}

int CosProduse::getCantitate(int produsID)
{
  return this->produse[produsID];
}

void CosProduse::deleteProdus(int produsID)
{
  this->produse.erase(produsID);
}

unordered_map<int, int>& CosProduse::getCos() {
  return this->produse;
}

void CosProduse::afisare()
{
  if (this->produse.empty()) {
    cout << "Cosul de produse este gol";
  }
  else
  {
    cout<<"ProdusID:    ///   Cantitate:"<<endl;

    for(auto const& x : this->produse)
      cout<<x.first<<" "<<x.second<<endl;
  }

}

json CosProduse::toJSON()
{
  return json(*this);
}