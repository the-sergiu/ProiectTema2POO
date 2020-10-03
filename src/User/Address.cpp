#include "Address.h"

using namespace std;

Address::Address()
{
    street = "";
    number = 0;
    block = "";
    apartment = 0;
}

Address::Address(const Address &address)
{
  this->apartment = address.apartment;
  this->block = address.block;
  this->county = address.county;
  this->number = address.number;
  this->street = address.street;
  this->locality = address.locality;
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
    county = jud;
    locality = loc;
    street = str;
    number = nr;
    block = bl;
    apartment = ap;
}

const Address &Address::operator=(const Address &adr)
{
  this->county = adr.county;
  this->locality = adr.locality;
  this->street = adr.street;
  this->number = adr.number;
  this->apartment = adr.apartment;
  this->block = adr.block;

  return *this;
}

void Address::setStrada(const string &str)
{
    street = str;
}

void Address::setNumar(int nr)
{
    number = nr;
}

void Address::setBlock(const string &bl)
{
    block = bl;
}

void Address::setApartment(int ap)
{
    apartment = ap;
}

void Address::setCounty(const string &jud)
{
    county = jud;
}

void Address::setLocality(const string &loc)
{
    locality = loc;
}

string &Address::getStreet()
{
  return this->street;
}

int Address::getNumber()
{
  return this->number;
}
string &Address::getBlock()
{
  return this->block;
}

int Address::getApartment()
{
  return this->apartment;
}

string &Address::getCounty()
{
  return county;
}

string &Address::getLocality()
{
  return locality;
}

bool Address::operator==(const Address &address)
{
  if (this->county != address.county)
    return false;
  if (this->locality != address.locality)
    return false;
  if (this->street != address.street)
    return false;
  if (this->number != address.number)
    return false;
  if (this->block != address.block)
    return false;
  if (this->apartment != address.apartment)
    return false;

  return true;
}

bool Address::operator!=(const Address &address)
{
  return !(*this == address);
}

ostream &operator<<(ostream &os, const Address &a)
{
  os << "Judet: " << a.county << ", Localitate: " << a.locality << ", Strada: " << a.street << ", nr. " << a.number << ", bl. " << a.block << ", ap. " << a.apartment << endl;
  return os;
}

json Address::toJSON()
{
  return json(*this);
}