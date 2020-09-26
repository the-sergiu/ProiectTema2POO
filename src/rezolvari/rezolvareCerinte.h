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


class rezolvareCerinte{
  private:
    Server *s;
    ofstream os;
  public:
    rezolvareCerinte();
    ~rezolvareCerinte();
    void Cerinta1();
    void Cerinta2a();
    void Cerinta2b();
    void Cerinta2c();
    void Cerinta2d();
    void Cerinta2e();
    void Cerinta2f();
};