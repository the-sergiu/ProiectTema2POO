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

  /*
   * @param seteaza campul County (judet)
   */
  void setCounty(const string &);
  /*
   * @param seteaza campul Locality (localitate)
   */
  void setLocality(const string &);
  /*
   * @param seteaza campul Street (strada)
   */
  void setStrada(const string &);
  /*
   * @param seteaza campul Number (numarul aferent strazii)
   */
  void setNumber(int);
  /*
   * @param seteaza campul Block (aferent blocului locuit)
   */
  void setBlock(const string &);
  /*
   * @param seteaza Apartment (numarul apartamentului)
   */
  void setApartment(int);
  /*
   * @return campul County (judet)
   */
  string &getCounty();
  /*
   * @return campul Locality (localitate)
   */
  string &getLocality();
  /*
   * @return campul Street (strada)
   */
  string &getStreet();
  /*
   * @return campul Number (aferent numarului de strada)
   */
  int getNumber();
  /*
   * @return campul Block (aferent blocului)
   */
  string &getBlock();
  /*
   * @return campul Apartment (aferent numarului de apartament)
   */
  int getApartment();

  // Operatori
  bool operator==(const Address &);
  bool operator!=(const Address &);
  friend ostream &operator<<(ostream &, const Address &);
  /*
    * ADMINISTRATIV - NU MODIFICATI
    */
  json toJSON();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Address, county, locality, street, number, block, apartment)
};
