#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/LRUCache/LRUCache.h"
#include "../json.hpp"
#include "../Solution/RezolvareQueries.h"
#include "JSONSerializer.h"
#include "FinalQuestionsHelper.h"

// Administrativ - NU MODIFICATI NIMIC

using json = nlohmann::json;

class TestHelper 
{
  Server *server;
  RezolvareQueries rezolvatorul;
  json input;
  public:
    TestHelper(const string&);
    ~TestHelper();
    void Init();
    json TestIerarhieClasaProdus(); // Test 1
    json TestIerarhieClasaUser();   // Test 2
    json TestClasaCosProduse();     // Test 3
    json TestCerinta2();
    json TestCerinta3a();
    json TestCerinta3b();
    json TestCerinta3c();          
    json TestCerinta3d();           
    json TestCerinta3e();
    json TestCerinta3f();
    json TestCerinta4();      // Test 4
    json TestCerinta5(const string&);
};