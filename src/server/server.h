#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "../produs/produsResigilat.h"
#include "../produs/FoodProduct.h"
#include "../user/userPremium.h"
#include "../user/userNonPremium.h"
#include "../cosproduse/cosProduse.h"
#include "../objectFactory/objectFactory.h"

using namespace std;


// template server ??
class Server
{
  private:
    
    static Server *instanta;

    int capacitateUsers;
    list<User*> usr;
    list<Product*> prod;

    // map id - produs
    unordered_map<int, Product*> produsId_Produs;
    // use case: produsId_Produs[id]->display();

    // map user - cosProduse
    unordered_map<int, CosProduse*> user_CosProduse;
    //use case: user_cosproduse[iduser].addProdus(idprodus, quantity)
    
    // LRUCache lru;
    // LRUCache bazat pe timp (queue/lista sortata dupa timestamp)

    // Singleton
    Server();
  public:
    static Server* InitializareServer();
    ~Server();

    unordered_map<int, Product*> getMap_Id_Produs();
    unordered_map<int, CosProduse*> getMap_User_CosProdus();

    void populareProduse(const json&);
    void populareUseri(const json&);

    void setMapProdusId_Produs();
    void setMapUser_CosProduse();


    list<Product*>& getListaProduse();
    list<User*>& getListaUseri();

    void requestAddProdus(int, int, int);
    void requestDeleteProdus(int, int);
    void requestModifyProdus(int, int, int);



};