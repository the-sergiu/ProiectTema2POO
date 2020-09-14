#pragma once
#include <iostream>
#include <list>
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

    static list<Produs*> getProdusList(json j);
     
    static json getJsonProdus(list<Produs*>&);

    static User* createUser(string, json::iterator);

    static list<User*> getUsersList(json j);

    static json getJsonUser(list<User*>&);
};