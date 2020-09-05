#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "produs/produsResigilat.h"
#include "produs/produsAlimentar.h"
#include "server/server.h"
#include "user/userPremium.h"
#include "user/userNonPremium.h"
#include "lrucache/lrucache.h"

using namespace std;


string returnClassType(string s);

// Instanta Singleton
Server *Server::instanta = 0;

int main() 
{
  // Produs** lista;
  // lista = new Produs* [5];
  // string str = "test";
  // lista[0] = new ProdusAlimentar(str, str, 2, 5.55, 110, str);
  // lista[1] = new ProdusNealimentar(str, str, str, 210, 5, 2, 2131.32143);
  // lista[2] = new ProdusRedus(str, str, str, 432, 5, 10, 4324234234, 10);
  // lista[3] = new ProdusReturnat(str, str, str, str, 432, 5, 2, 432423);
  // lista[4] = new ProdusResigilat(str, str, str, str, 789, 3, 5, 4234, 10, 22);

  // for (int i = 0 ; i < 5; i++)
  // {
  //   cout << "Element " << i+1 << ":" << endl;
  //   lista[i] -> afisare();
  //   cout << endl;
  // }


  // cout << endl;
  // ProdusReturnat p(str, str, str, 432, 5, 2, 432423);
  // cout << returnClassType(typeid(*(lista[1])).name()) << endl;
  // ProdusResigilat* pa = dynamic_cast<ProdusResigilat*>(lista[4]);
  // cout<<pa->getProcentUzura() << endl;

  // auto it = lista2.begin();
  // (*it)->afisare();
/* TEST INITIALIZARE SERVER */
  Server *serv;
  serv = Server::InitializareServer();
  serv->populareProduse("server/produse.txt");
  serv->setMapProdusId_Produs();
  serv->populareUseri("server/users.txt");
  serv->setMapuser_CosProduse();
  
/*TESTARE ADAUGARE PRODUS IN COS PENTRU USER SI PRODUS DE TEST*/
  // serv->requestAddProdus(251, 2, 10);


  // list<Produs*> lst = serv->getListaProduse();
  // for (auto it = lst.begin(); it != lst.end(); it++){
  //   (*it)->afisare();
  //   cout<<endl;
  // }

/* TEST MAP PRODUSE  */
  //unordered_map<int, Produs*> mp;
 // mp[0] = new ProdusAlimentar(str, 110, 5.55, str, str);
 // mp[0]->afisare();

  // for (int i = 0 ; i < 5; i++)
  // {
  //   cout << "Element " << i+1 << ":" << endl;
  //   lista[i] -> afisare();
  //   cout << endl;
  // }

/* Test USER LIST */
  // Adresa adr(str, 2, str, 9);
  // list<User*> userList;
  // unordered_map<int, int> reduceri;
  // reduceri[0] = 5;

  // userList.push_back(new UserPremium(reduceri, str, str, str, 1, str, adr, adr, 69));

  // userList.push_back(new UserNonPremium(str, str, str, 1, str, adr, adr, 15));
  
  // for (auto it = userList.begin(); it != userList.end(); it++){
  //   (*it)->vizualizareUser();
  //   cout<<endl;
  // }

/* TEST LRU CACHE */
  // cout << "LRU CACHE TEST: " << endl; 
  // vector<int> lruTest = {1, 2, 3, 2, 5, 3, 4, 5, 8, 9};
  // LRUCache obj(4);
  // // check processing
  // vector<int> ans = obj.processRequests(lruTest);
  // for (int i = 0; i < ans.size(); i++)
  // {
  //   cout << ans[i] << " ";
  // }
  // // check set-get LRU
  // cout << endl << "setLRU-getLRU TEST: " << endl;
  // vector<int> aux = obj.getLRU();
  // // obj.setLRU(ans);
  
  // for (auto it = aux.begin(); it != aux.end(); it++)
  // {
  //   cout << *it << " ";
  // }
  // cout << endl << endl;
  // // check get-set cap
  // obj.setCapacity(20);
  // int a = obj.getSize(); int b = obj.getCapacity();
  // cout << a << " " << b;
  // cout << endl;




  cout << endl << "END" << endl;  
  return 0;
} 

  



// date enunturi clare, date deintrare clare, date de iesire fixe
// modificam functia de getPret si pentru Alimentar/ProdusNealimentar, plus
// calcul reducere Resigilat, Redus 
// static? stoc 
// operatii in functie de id - de cautare; eliminam string categorie