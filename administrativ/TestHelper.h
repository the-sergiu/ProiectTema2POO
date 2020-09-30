#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../src/produs/produsResigilat.h"
#include "../src/produs/produsAlimentar.h"
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
    json TestCerinta1();
    json TestCerinta2a();
    json TestCerinta2b();
    json TestCerinta2c();           // TODO
    json TestCerinta2d();           // TODO
    json TestCerinta2e();
    json TestCerinta2f();
};