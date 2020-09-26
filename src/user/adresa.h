#pragma once
#include <string>
#include <iostream>
#include "../json.hpp"

using json = nlohmann::json;
using namespace std;

class Adresa
{
  private:
  string judet;
  string localitate;
  string strada;
  int numar;
  string bloc;
  int apartament;

  public:
  Adresa();
  Adresa(const Adresa&);
  Adresa(const string&, const string&, const string&, int, const string&, int);
  Adresa& operator=(const Adresa&);


  void setJudet(const string&);
  void setLocalitate(const string&);
  void setStrada(const string&);
  void setNumar(int);
  void setBloc(const string&);
  void setApartament(int);

  string& getJudet();
  string& getLocalitate();
  string& getStrada();
  int getNumar();
  string& getBloc();
  int getApartament();

  bool operator==(const Adresa &);
  bool operator!=(const Adresa &);

  friend ostream& operator << (ostream&, const Adresa&);

  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Adresa, judet, localitate, strada, numar, bloc, apartament)
};
