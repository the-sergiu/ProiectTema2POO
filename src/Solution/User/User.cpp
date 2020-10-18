#include "User.h"
using namespace std;

User::~User()
{
	throw("undefined");
}

User::User()
{
	throw("undefined");
}

User::User(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int UserId, const string &lastName, const string &prenume, const string &email)
	: billingData(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf),
	  deliveryData(judetl, localitatel, stradal, nr_stradal, blocl, apartamentl)
{
	throw("undefined");
}

User::User(const User &u)
{
	throw("undefined");
}

const User &User::operator=(const User &u)
{
	throw("undefined");
}

// Set-eri
void User::setLastName(const string &lastName)
{
	throw("undefined");
}
void User::setFirstName(const string &firstName)
{
	throw("undefined");
}
void User::setEmail(const string &email)
{
	throw("undefined");
}
void User::setUserID(int userID)
{
	throw("undefined");
}
void User::setBillingData(const Address &billingData)
{
	throw("undefined");
}
void User::setDeliveryData(const Address &deliveryData)
{
	throw("undefined");
}
// Get-eri
string &User::getLastName()
{
	throw("undefined");
}
string &User::getFirstName()
{
	throw("undefined");
}
string &User::getEmail()
{
	throw("undefined");
}
int User::getUserID() const
{
	throw("undefined");
}

Address &User::getBillingData()
{
	throw("undefined");
}
Address &User::getDeliveryData()
{
	throw("undefined");
}

json User::toJSON()
{
	return json(*this);
}
