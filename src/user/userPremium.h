#pragma once
#include "user.h"
#include <string>

using namespace std;

class UserPremium : public User
{
  protected:
    unordered_map<int, int> reduceri;// idProdus-procentReducere
    int costAbonamentPremium;
  
  public:
    UserPremium();

    UserPremium(const string&, const string&, const string&, int, const string&, int, const string&, const string&, const string&, int, const string&, int, int, const string&, const string&, const string&, int, const unordered_map<int,int>&);

    string getUserType();
    void vizualizareUser();
    float getCostTransport();
    
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserPremium, dateFacturare, dateLivrare, nume, prenume, email, UserId, costAbonamentPremium, reduceri)
};