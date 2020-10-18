#include "BasicUser.h"

using namespace std;

BasicUser::BasicUser()
{
	throw("undefined");
}

BasicUser::BasicUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, float costTransport) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	throw("undefined");
}

BasicUser::BasicUser(const BasicUser &unp) : User(unp)
{
	throw("undefined");
}

BasicUser &BasicUser::operator=(const BasicUser &unp)
{
	throw("undefined");
}

void BasicUser::setTransportCost(int cost)
{
	throw("undefined");
}

float BasicUser::getTransportCost()
{
	throw("undefined");
}

void BasicUser::displayUser()
{
	throw("undefined");
}

string BasicUser::getUserType()
{
	throw("undefined");
}

json BasicUser::toJSON()
{
	return json(*this);
}
