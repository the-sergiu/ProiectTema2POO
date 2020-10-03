#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "rezolvari/rezolvareCerinte.h"
#include "Product/ResealedProduct.h"
#include "Product/FoodProduct.h"
#include "server/server.h"
#include "user/userPremium.h"
#include "user/userNonPremium.h"
#include "lrucache/lrucache.h"
#include "objectFactory/objectFactory.h"
#include "../administrativ/TestHelper.cpp"

using namespace std;


// Instanta Singleton
Server *Server::instance = 0;

int main(int argc, char** argv) 
{
  json result;

  TestHelper p(argv[1]);


  // TestHelper p;
  RezolvareCerinte rez;

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
        result = p.TestCerinta2();
        break;
      case 6:
        result = p.TestCerinta3a();
        break;
      case 7:
        result = p.TestCerinta3b();
        break;
      case 8:
        result = p.TestCerinta3c();
        break;
      case 9:
        result = p.TestCerinta3d();
        break;
      case 10:
        result = p.TestCerinta3e();
        break;
      case 11:
        result = p.TestCerinta3f();
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