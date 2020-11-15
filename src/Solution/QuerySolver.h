#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../utils/utility.h"
#include "Product/ResealedProduct.h"
#include "Product/FoodProduct.h"
#include "Server/Server.h"
#include "User/PremiumUser.h"
#include "User/BasicUser.h"
#include "LRUCache/LRUCache.h"
#include "../utils/objectFactory/objectFactory.h"


class QuerySolver{
  private:
    Server *server;
    LRUCache *lru;
  public:
    QuerySolver();
    ~QuerySolver();
    list<Product*> Cerinta3a();
    list<User*> Cerinta3b();
    list<Product*> Cerinta3c();
    list<Product*> Cerinta3d();
    list<User*> Cerinta3e();
    list<User*> Cerinta3f();
};