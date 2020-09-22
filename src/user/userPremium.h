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
    UserPremium();

    UserPremium(const string&, const string&, const string&, int, const string&, int, const string&, int, const string&, int, int, const string&, const string&, const string&, const unordered_map<int,int>&);

    void vizualizareUser();

    void setReduceri(unordered_map<int,int>);
    void setCostAbonamentPremium(int cap);

    unordered_map<int, int> getReduceri();
    int getCostAbonamentPremium();
    
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserPremium, dateFacturare, dateLivrare, nume, prenume, email, UserId, reduceri, costAbonamentPremium)
};