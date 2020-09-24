#pragma once
#include "../src/produs/produsResigilat.h"
#include "../src/produs/produsAlimentar.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../src/json.hpp"

using json = nlohmann::json;

class TestHelper {
  public:
    json TestIerarhieClasaProdus();
    json TestIerarhieClasaUser();
    json TestClasaCosProduse();
};