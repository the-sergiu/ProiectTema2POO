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
  s->populareProduse("src/files/input/input.json");
  s->setMapProdusId_Produs();

  return 0;
} 

  



// date enunturi clare, date deintrare clare, date de iesire fixe
// modificam functia de getPret si pentru Alimentar/ProdusNealimentar, plus
// calcul reducere Resigilat, Redus 
// static? stoc 
// operatii in functie de id - de cautare; eliminam string categorie