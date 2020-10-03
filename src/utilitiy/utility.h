#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../produs/NonFoodProduct.h"
#include "../produs/FoodProduct.h"

class Utility{

public:
    static bool compareProdusNealimentar(Product*, Product*);

    static bool compareProdusAlimentar(Product*, Product*);
};