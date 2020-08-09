#include "cosProduse.h"


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