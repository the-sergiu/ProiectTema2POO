#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "../produs/produsResigilat.h"
#include "../produs/produsAlimentar.h"
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
    list<Produs*> prod;

    // map id - produs
    unordered_map<int, Produs*> produsId_Produs;
    // use case: produsId_Produs[id]->afisare();

    // map user - cosProduse
    unordered_map<int, CosProduse*> user_CosProduse;
    //use case: user_cosproduse[iduser].addProdus(idprodus, cantitate)
    
    // LRUCache lru;
    // LRUCache bazat pe timp (queue/lista sortata dupa timestamp)

    // Singleton
    Server();
  public:
    static Server* InitializareServer();
    ~Server();

    void populareProduse(const string&);
    void populareUseri(const string&);

    void setMapProdusId_Produs();
    void setMapuser_CosProduse();


    list<Produs*>& getListaProduse();
    list<User*>& getListaUseri();

    void requestAddProdus(int, int, int);
    void requestDeleteProdus(int, int);
    void requestModifyProdus(int, int, int);


    
    // query(db, a, b, c)
};

/*



Fisier:
Produs 1, 2 etc
Citim produs cu produs intr-un pointer temp

Produs *pointer_temp = new ProdusAlimentar/Nealimentar(ID, ....)

map[pointer_temp->getID()] = pointer_temp
string nume
sting blabla
////



*/