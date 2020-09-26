#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

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
};