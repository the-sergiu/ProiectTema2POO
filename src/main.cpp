#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "produs/produsResigilat.h"
#include "produs/produsAlimentar.h"
#include "server/server.h"
#include "user/userPremium.h"
#include "user/userNonPremium.h"
#include "lrucache/lrucache.h"
#include "objectFactory/objectFactory.h"

using namespace std;


string returnClassType(string s);

// Instanta Singleton
Server *Server::instanta = 0;

int main() 
{
  Server *s = Server::InitializareServer();

  //Testare citire produse din json
  s->populareProduse("src/files/input/input_produse.json");
  s->setMapProdusId_Produs();

  //Testare citire useri din json
  s->populareUseri("src/files/input/input_useri.json");
  s->setMapUser_CosProduse();

  json jtest1 = ObjectFactory::getJsonUser(s->getListaUseri());
  
  ofstream os1("src/files/output/output_useri.json");
  os1 << jtest1; 

  json jtest2 = ObjectFactory::getJsonProdus(s->getListaProduse());
  
  ofstream os2("src/files/output/output_produse.json");
  os2 << jtest2; 

  return 0;
} 

  



// date enunturi clare, date deintrare clare, date de iesire fixe
// modificam functia de getPret si pentru Alimentar/ProdusNealimentar, plus
// calcul reducere Resigilat, Redus 
// static? stoc 
// operatii in functie de id - de cautare; eliminam string categorie