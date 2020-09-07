#pragma once
#include <string>
#include <iostream>
#include "../json.hpp"

using namespace std;

class Adresa
{
  private:
  string judet;
  string oras;
  string strada;
  int numar;
  string bloc;
  int apartament;

  public:
  Adresa();
  Adresa(const string&, const string&, const string&, int, const string&, int);

  void setJudet(const string&);
  void setOras(const string&);
  void setStrada(const string&);
  void setNumar(int);
  void setBloc(const string&);
  void setApartament(int);

  string& getJudet();
  string& getOras();
  string& getStrada();
  int getNumar();
  string& getBloc();
  int getApartament();

  friend ostream& operator << (ostream&, const Adresa&);

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Adresa, judet, oras, strada, numar, bloc)
};
