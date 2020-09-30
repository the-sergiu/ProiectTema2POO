#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../produs/produsResigilat.h"
#include "../produs/produsAlimentar.h"
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
    void Cerinta1();
    list<Produs*> Cerinta2a();
    list<User*> Cerinta2b();
    void Cerinta2c();
    void Cerinta2d();
    list<User*> Cerinta2e();
    list<User*> Cerinta2f();
};