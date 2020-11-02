#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../json.hpp"

using namespace std;
using json = nlohmann::json;

/*
  *structura ajutatoare ce va fi folosita pentru ultima cerinta
*/
typedef struct query
{
    int productID;
    int userID;
    string operation;
    int quantity;
} Query;

/*
 * @param j obiectul json din care se vor citi query-urile
 * @return vector de query-uri
 */
vector<Query> getQuery(json &j);
