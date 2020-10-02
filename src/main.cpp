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
#include "../administrativ/TestHelper.cpp"

using namespace std;


// Instanta Singleton
Server *Server::instanta = 0;

int main(int argc, char** argv) 
{
  json result;

  TestHelper p(argv[1]);


  TestHelper p;
  rezolvareCerinte rez;

   rez.Cerinta1();
   rez.Cerinta2d();
 // rez.Cerinta2a();
 // rez.Cerinta2b();
  //rez.Cerinta2d();
  //rez.Cerinta2e();
  // rez.Cerinta2f();
 
  // string str = "test"

  try{
    
    if (argc != 4)
    {
      throw "Error: Executable requires precisely 4 arguments!";
    }

    ofstream oStream(argv[2]);
    int testIndex = atoi(argv[3]);

    switch (testIndex) 
    {
      case 1:
        result = p.TestIerarhieClasaProdus();
        break;
      case 2:
        result = p.TestIerarhieClasaUser();
        break;
      case 3:
        result = p.TestClasaCosProduse();
        break;
      case 4:
        result = p.TestLRUCacheSimple();
        break;
      case 5:
        result = p.TestCerinta1();
        break;
      case 6:
        result = p.TestCerinta2a();
        break;
      case 7:
        result = p.TestCerinta2b();
        break;
      case 8:
        result = p.TestCerinta2c();
        break;
      case 9:
        result = p.TestCerinta2d();
        break;
      case 10:
        result = p.TestCerinta2e();
        break;
      case 11:
        result = p.TestCerinta2f();
        break;
      default:
        break;
    }

    oStream<<result;

    return 0;
  }
  catch (const char *ex)
  {
    cout<<ex;
  }


  return 0;

} 