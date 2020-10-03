#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "../src/json.hpp"
#include "../src/produs/produsResigilat.h"
#include "../src/produs/FoodProduct.h"
#include "../src/user/userPremium.h"
#include "../src/user/userNonPremium.h"
#include "../src/cosproduse/cosProduse.h"

using namespace std;
using json = nlohmann::json;


class JSONSerializer 
{
    public:
        static json FromProdusMap(const unordered_map<int, Product*> produse)
        {
            json result;

            for (auto& it: produse)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }

        static json FromUserMap(const unordered_map<int, CosProduse*>& cosuriProduse)
        {
            json result;

            for (auto& it : cosuriProduse)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }
};