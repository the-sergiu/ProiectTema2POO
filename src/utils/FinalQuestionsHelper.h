#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../json.hpp"

using namespace std;
using json = nlohmann::json;

typedef struct lrubluprint
{
    int capacity;
    vector<int> allLRUOperations;
} LRU_blueprint;

typedef struct query
{
    int productID;
    int userID;
    string operation;
    int quantity;
} Query;

/*
      * @param paramName - param description
      * @return what and when
      */
LRU_blueprint getLruBlueprint(json &);
/*
      * @param paramName - param description
      * @return what and when
      */
json writeLruFinalState(vector<int> &);
/*
      * @param paramName - param description
      * @return what and when
      */
vector<Query> getQuery(json &);
/*
      * @param paramName - param description
      * @return what and when
      */
json writeFinalState(vector<Query> &, vector<int> &);

json queryToJson(Query &);