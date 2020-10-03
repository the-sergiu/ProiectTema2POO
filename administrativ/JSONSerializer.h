#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "../src/json.hpp"
#include "../src/Product/ResealedProduct.h"
#include "../src/Product/FoodProduct.h"
#include "../src/User/PremiumUser.h"
#include "../src/User/BasicUser.h"
#include "ShoppingCart/ShoppingCart.h"

using namespace std;
using json = nlohmann::json;


class JSONSerializer 
{
    public:
        static json fromProductMap(const unordered_map<int, Product*> products)
        {
            json result;

            for (auto& it: products)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }

        static json FromUserMap(const unordered_map<int, ShoppingCart*>& cartsOfProducts)
        {
            json result;

            for (auto& it : cartsOfProducts)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }
};