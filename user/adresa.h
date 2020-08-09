#pragma once
#include <string>
#include <iostream>

using namespace std;

class Adresa
{
  private:
  string strada;
  int numar;
  string bloc;
  int apartament;

  public:
  Adresa();
  Adresa(const string&, int, const string&, int);

  void setStrada(const string&);
  void setNumar(int);
  void setBloc(const string&);
  void setApartament(int);

  string& getStrada();
  int getNumar();
  string& getBloc();
  int getApartament();

  friend ostream& operator << (ostream&, Adresa&);
};
