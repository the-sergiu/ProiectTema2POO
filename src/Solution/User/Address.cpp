#include "Address.h"

using namespace std;

Address::Address()
{
	throw("undefined");
}

Address::Address(const Address &address)
{
	throw("undefined");
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
	throw("undefined");
}

const Address &Address::operator=(const Address &adr)
{
	throw("undefined");
}

void Address::setStrada(const string &str)
{
	throw("undefined");
}

void Address::setNumber(int nr)
{
	throw("undefined");
}

void Address::setBlock(const string &bl)
{
	throw("undefined");
}

void Address::setApartment(int ap)
{
	throw("undefined");
}

void Address::setCounty(const string &jud)
{
	throw("undefined");
}

void Address::setLocality(const string &loc)
{
	throw("undefined");
}

string &Address::getStreet()
{
	throw("undefined");
}

int Address::getNumber()
{
	throw("undefined");
}
string &Address::getBlock()
{
	throw("undefined");
}

int Address::getApartment()
{
	throw("undefined");
}

string &Address::getCounty()
{
	throw("undefined");
}

string &Address::getLocality()
{
	throw("undefined");
}

bool Address::operator==(const Address &address)
{
	throw("undefined");
}

bool Address::operator!=(const Address &address)
{
	throw("undefined");
}

ostream &operator<<(ostream &os, const Address &a)
{
	throw("undefined");
}

json Address::toJSON()
{
	return json(*this);
}