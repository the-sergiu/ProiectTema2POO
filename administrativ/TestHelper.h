#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../src/Product/ResealedProduct.h"
#include "../src/Product/FoodProduct.h"
#include "../src/lrucache/lrucache.h"
#include "../src/json.hpp"
#include "../src/rezolvari/rezolvareCerinte.h"
#include "JSONSerializer.h"

using json = nlohmann::json;

class TestHelper 
{
  Server *server;
  RezolvareCerinte rezolvatorul;
  json input;
  public:
    TestHelper(const string&);
    ~TestHelper();
    void Init();
    json TestIerarhieClasaProdus(); // Test 1
    json TestIerarhieClasaUser();   // Test 2
    json TestClasaCosProduse();     // Test 3
    json TestLRUCacheSimple();      // Test 4
    json TestCerinta2();
    json TestCerinta3a();
    json TestCerinta3b();
    json TestCerinta3c();          
    json TestCerinta3d();           
    json TestCerinta3e();
    json TestCerinta3f();
};