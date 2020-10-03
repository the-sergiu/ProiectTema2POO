#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../utilitiy/utility.h"
#include "../produs/ResealedProduct.h"
#include "../produs/FoodProduct.h"
#include "../server/server.h"
#include "../user/userPremium.h"
#include "../user/userNonPremium.h"
#include "../lrucache/lrucache.h"
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