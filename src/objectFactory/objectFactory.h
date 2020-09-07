#pragma once
#include <iostream>
#include <vector>
#include "../json.hpp"
#include "../produs/produsResigilat.h"

using namespace std;
using json = nlohmann::json;

#define TYPE_KEY "type"

const char* produsTypes[] = {"alimentar", "nealimentar", "redus", "returnat", "resigilat"};

class ObjectFactory{

public:

    static Produs* createProdus(string type, json::iterator it) {

        if (type == produsTypes[0]) {

            ProdusAlimentar *newProdus = new ProdusAlimentar();   
            *newProdus = it->get<ProdusAlimentar>();
             return newProdus;
        }

        if (type == produsTypes[1]) {

            ProdusNealimentar *newProdus = new ProdusNealimentar();
            *newProdus = it->get<ProdusNealimentar>();
            return newProdus;
        }

        if (type == produsTypes[2]) {

            ProdusRedus *newProdus = new ProdusRedus();
            *newProdus = it->get<ProdusRedus>();
            return newProdus;
        }

        if (type == produsTypes[3]) {

            ProdusReturnat *newProdus = new ProdusReturnat();
            *newProdus = it->get<ProdusReturnat>();
            return newProdus;
        }

        if (type == produsTypes[4]) {
            
            ProdusResigilat *newProdus = new ProdusResigilat();
            *newProdus = it->get<ProdusResigilat>();
            return newProdus;
        }
    }  

    static vector<Produs*> getProdusVector(string fileName){

        ifstream i("test.json");
        json j;
        vector<Produs*> vec;

        i >> j;

        for (json::iterator it = j.begin(); it != j.end(); ++it) {

            Produs *p = createProdus((*it)[TYPE_KEY], it);
            vec.push_back(p);
        }
        return vec;
    }  
     
    static json getJsonProdus(vector<Produs*>& vec){

        json outj;

        for (int i = 0; i < vec.size(); i++) {
            outj.push_back(vec[i]->toJSON());
        }

        return outj;
    } 

};