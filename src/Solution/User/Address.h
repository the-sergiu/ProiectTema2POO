#pragma once
#include <string>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Address
{
private:
  string county;
  string locality;
  string street;
  int number;
  string block;
  int apartment;

public:
  // Constructori
  Address();
  Address(const Address &);
  Address(const string &, const string &, const string &, int, const string &, int);

  // Operator =
  const Address &operator=(const Address &);

  // Set
  void setCounty(const string &);
  void setLocality(const string &loc);
  void setStrada(const string &);
  void setNumar(int);
  void setBlock(const string &bl);
  void setApartment(int);

  // Get
  string &getCounty();
  string &getLocality();
  string &getStreet();
  int getNumber();
  string &getBlock();
  int getApartment();

  // Operatori
  bool operator==(const Address &);
  bool operator!=(const Address &);
  friend ostream &operator<<(ostream &, const Address &);

  // Administrativ - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Address, county, locality, street, number, block, apartment)
};
