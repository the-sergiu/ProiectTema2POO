#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../src/json.hpp"

using namespace std;
using json = nlohmann::json;


typedef struct lrubluprint{
    int capacity;
    vector<int> allLruOoperations;
}LRU_blueprint;

typedef struct query{
    int productID;
    int userID;
    string operation;
}Query;

LRU_blueprint getLruBlueprint(json&);

json writeLruFinalState(vector<int>&);

vector<Query> getQuery(json&);

json writeFinalState(vector<Query>&, vector<int>&);

json queryToJson(Query&);