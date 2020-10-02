#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../produs/produsNealimentar.h"
#include "../produs/produsAlimentar.h"

class Utility{

public:
    static bool compareProdusNealimentar(Produs*, Produs*);

    static bool compareProdusAlimentar(Produs*, Produs*);
};