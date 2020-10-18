#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser()
{
	throw("undefined");
}

PremiumUser::PremiumUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf,
						 const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl,
						 int id, const string &nume, const string &prenume, const string &email, int premiumSubscriptionCost, const map<int, int> &discounts)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	throw("undefined");
}

PremiumUser::PremiumUser(const PremiumUser &up) : User(up)
{
	throw("undefined");
}

const PremiumUser &PremiumUser::operator=(const PremiumUser &up)
{
	throw("undefined");
}

void PremiumUser::displayUser()
{
	throw("undefined");
}

string PremiumUser::getUserType()
{
	throw("undefined");
}

float PremiumUser::getTransportCost()
{
	throw("undefined");
}

map<int, int> &PremiumUser::getDiscounts()
{
	throw("undefined");
}

void PremiumUser::setDiscounts(map<int, int> red)
{
	throw("undefined");
}

void PremiumUser::setPremiumSubscriptionCost(int cap)
{
	throw("undefined");
}

int PremiumUser::getPremiumSubscriptionCost()
{
	throw("undefined");
}

json PremiumUser::toJSON()
{
	return json(*this);
}