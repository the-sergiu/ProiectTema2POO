#pragma once
#include "user.h"
#include <string>

using namespace std;

class UserPremium : public User
{
  protected:
    // idProdus-procentReducere
    unordered_map<int, int> reduceri;
    int costAbonamentPremium;
  
  public:
    UserPremium(const string&, const string&, const string&, int, const string&, int, const string&, int, const string&, int, int, const string&, const string&, const string&, const unordered_map<int,int>&);

    void vizualizareUser();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserPremium, dateFacturare, dateLivrare, nume, prenume, email, UserId, reduceri, costAbonamentPremium)
};