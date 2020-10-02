#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "../src/json.hpp"

using namespace std;
using json = nlohmann::json;


class CosProduse
{
  private:
    unordered_map<int, int> produse;
    string metodaPlata;

  public:
    CosProduse();
    CosProduse(const string&);
    string& getMetodaPlata();
    void setMetodaPlata(const string&);
    int getCantitate(int);
    void addProdus(int, int);
    void deleteProdus(int);
    unordered_map<int,int>& getCos();
    void afisare();
    json toJSON();
    
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CosProduse, produse, metodaPlata)
};