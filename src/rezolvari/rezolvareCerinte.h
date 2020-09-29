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
    void Cerinta2a();
    void Cerinta2b();
    void Cerinta2c();
    void Cerinta2d();
    void Cerinta2e();
    void Cerinta2f();
};