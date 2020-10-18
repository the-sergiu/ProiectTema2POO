#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"

class Utility{

public:
    static bool compareProdusNealimentar(Product*, Product*);

    static bool compareProdusAlimentar(Product*, Product*);
};