#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../utilitiy/utility.h"
#include "../Product/ResealedProduct.h"
#include "../Product/FoodProduct.h"
#include "../Server/Server.h"
#include "../User/PremiumUser.h"
#include "../User/BasicUser.h"
#include "../LRUCache/LRUCache.h"
#include "../objectFactory/objectFactory.h"


class RezolvareCerinte{
  private:
    Server *server;
  public:
    RezolvareCerinte();
    ~RezolvareCerinte();
    void Cerinta2();
    list<Product*> Cerinta3a();
    list<User*> Cerinta3b();
    list<Product*> Cerinta3c();
    list<Product*> Cerinta3d();
    list<User*> Cerinta3e();
    list<User*> Cerinta3f();
};