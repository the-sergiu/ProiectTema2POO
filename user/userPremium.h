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

    // UserPremium();
    UserPremium(unordered_map<int, int>&, const string&, const string&, const string&, int, const string&, const Adresa&, const Adresa&, int);

    void vizualizareUser();
};