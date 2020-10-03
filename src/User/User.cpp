#include "User.h"
using namespace std;

User::~User() {}

User::User() {}

User::User(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int UserId, const string &lastName, const string &prenume, const string &email)
        :   billingData(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf),
            deliveryData(judetl, localitatel, stradal, nr_stradal, blocl, apartamentl)
{
  this->UserID = UserId;
  this->lastName = lastName;
  this->firstName = prenume;
  this->email = email;
}

User::User(const User &u)
{
  this->billingData = u.billingData;
  this->deliveryData = u.deliveryData;
  this->lastName = u.lastName;
  this->firstName = u.firstName;
  this->email = u.email;
  this->UserID = u.UserID;
}

const User &User::operator=(const User &u)
{
  this->billingData = u.billingData;
  this->deliveryData = u.deliveryData;
  this->lastName = u.lastName;
  this->firstName = u.firstName;
  this->email = u.email;
  this->UserID = u.UserID;

  return *this;
}

// Set-eri
void User::setLastName(const string &lastName)
{
  this->lastName = lastName;
}
void User::setFirstName(const string &firstName)
{
  this->firstName = firstName;
}
void User::setEmail(const string &email)
{
  this->email = email;
}
void User::setUserID(int userID)
{
  this->UserID = userID;
}
void User::setBillingData(const Address &billingData)
{
  this->billingData = billingData;
}
void User::setDeliveryData(const Address &deliveryData)
{
  this->deliveryData = deliveryData;
}
// Get-eri
string &User::getLastName()
{
  return this->lastName;
}
string &User::getFirstName()
{
  return this->firstName;
}
string &User::getEmail()
{
  return this->email;
}
int User::getUserID() const
{
  return this->UserID;
}

Address &User::getBillingData()
{
  return this->billingData;
}
Address &User::getDeliveryData()
{
  return this->deliveryData;
}

json User::toJSON()
{
  return json(*this);
}
