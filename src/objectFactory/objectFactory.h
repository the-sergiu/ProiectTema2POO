#pragma once
#include <iostream>
#include <vector>
#include "../json.hpp"
#include "../produs/produsAlimentar.h"
#include "../produs/produsResigilat.h"
#include "../user/userNonPremium.h"
#include "../user/userPremium.h"
#include <fstream>

using namespace std;
using json = nlohmann::json;

#define TYPE_KEY "type"

class ObjectFactory{

public:

    static Produs* createProdus(string, json::iterator);

    static vector<Produs*> getProdusVector(json j);
     
    static json getJsonProdus(vector<Produs*>&);

    static User* createUser(string, json::iterator);

    static vector<User*> getUsersVector(json j);

    static json getJsonUser(vector<User*>&);
};