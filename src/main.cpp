#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "rezolvari/rezolvareCerinte.h"
#include "produs/produsResigilat.h"
#include "produs/produsAlimentar.h"
#include "server/server.h"
#include "user/userPremium.h"
#include "user/userNonPremium.h"
#include "lrucache/lrucache.h"
#include "objectFactory/objectFactory.h"

using namespace std;


// Instanta Singleton
Server *Server::instanta = 0;

int main() 
{

  rezolvareCerinte rez;

  rez.Cerinta1();
  //rez.Cerinta2a();
  //rez.Cerinta2b();
  //rez.Cerinta2c();
  //rez.Cerinta2d();
  //rez.Cerinta2e();
  rez.Cerinta2f();

  return 0;
} 

  



// date enunturi clare, date deintrare clare, date de iesire fixe
// modificam functia de getPret si pentru Alimentar/ProdusNealimentar, plus
// calcul reducere Resigilat, Redus 
// static? stoc 
// operatii in functie de id - de cautare; eliminam string categorie