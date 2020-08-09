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

void Produs::scadeCantitate(int cantitateCeruta)
{
  this->cantitate -= cantitateCeruta;
}

void Produs::cresteCantitate(int cantitateCeruta)
{
  this->cantitate += cantitateCeruta;
}