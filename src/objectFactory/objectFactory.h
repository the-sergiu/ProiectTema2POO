#pragma once
#include <iostream>
#include <list>
#include "../json.hpp"
#include "../Product/FoodProduct.h"
#include "../Product/ResealedProduct.h"
#include "../User/BasicUser.h"
#include "../User/PremiumUser.h"
#include <fstream>

using namespace std;
using json = nlohmann::json;

#define TYPE_KEY "type"

class ObjectFactory{

public:

    static Product* createProdus(string, json::iterator);

    static list<Product*> getProdusList(json j);
     
    static json getJsonProdus(list<Product*>&);

    static User* createUser(string, json::iterator);

    static list<User*> getUserList(json j);

    static json getJsonUser(list<User*>&);
};