//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//
//#include "Product/produsResigilat.h"
//#include "Product/produsAlimentar.h"
//#include "Server/Server.h"
//#include "User/userPremium.h"
//#include "User/userNonPremium.h"
//#include "LRUCache/LRUCache.h"
//
//using namespace std;
//
//
//string returnClassType(string s);
//
//// Instanta Singleton
//Server *Server::instance = 0;
//
//int main()
//{
//  // Product** lista;
//  // lista = new Product* [5];
//  // string str = "test";
//  // lista[0] = new FoodProduct(str, str, 2, 5.55, 110, str);
//  // lista[1] = new NonFoodProduct(str, str, str, 210, 5, 2, 2131.32143);
//  // lista[2] = new DiscountedProduct(str, str, str, 432, 5, 10, 4324234234, 10);
//  // lista[3] = new ReturnedProduct(str, str, str, str, 432, 5, 2, 432423);
//  // lista[4] = new ResealedProduct(str, str, str, str, 789, 3, 5, 4234, 10, 22);
//
//  // for (int i = 0 ; i < 5; i++)
//  // {
//  //   cout << "Element " << i+1 << ":" << endl;
//  //   lista[i] -> display();
//  //   cout << endl;
//  // }
//
//
//  // cout << endl;
//  // ReturnedProduct p(str, str, str, 432, 5, 2, 432423);
//  // cout << returnClassType(typeid(*(lista[1])).lastName()) << endl;
//  // ResealedProduct* pa = dynamic_cast<ResealedProduct*>(lista[4]);
//  // cout<<pa->getWearPercentage() << endl;
//
//  // auto it = lista2.begin();
//  // (*it)->display();
///* TEST INITIALIZARE SERVER */
//  Server *serv;
//  serv = Server::ServerInit();
//  serv->populateProducts("Server/shoppingCart.txt");
//  serv->set__ProductID__ProductObj__();
//  serv->populateUsers("Server/users.txt");
//  serv->setMapuser_CosProduse();
//
///*TESTARE ADAUGARE PRODUS IN COS PENTRU USER SI PRODUS DE TEST*/
//  // serv->requestAddProduct(251, 2, 10);
//
//
//  // list<Product*> lst = serv->getProductsList();
//  // for (auto it = lst.begin(); it != lst.end(); it++){
//  //   (*it)->display();
//  //   cout<<endl;
//  // }
//
///* TEST MAP PRODUSE  */
//  //unordered_map<int, Product*> mp;
// // mp[0] = new FoodProduct(str, 110, 5.55, str, str);
// // mp[0]->display();
//
//  // for (int i = 0 ; i < 5; i++)
//  // {
//  //   cout << "Element " << i+1 << ":" << endl;
//  //   lista[i] -> display();
//  //   cout << endl;
//  // }
//
///* Test USER LIST */
//  // Address adr(str, 2, str, 9);
//  // list<User*> userList;
//  // unordered_map<int, int> discounts;
//  // discounts[0] = 5;
//
//  // userList.push_back(new PremiumUser(discounts, str, str, str, 1, str, adr, adr, 69));
//
//  // userList.push_back(new BasicUser(str, str, str, 1, str, adr, adr, 15));
//
//  // for (auto it = userList.begin(); it != userList.end(); it++){
//  //   (*it)->displayUser();
//  //   cout<<endl;
//  // }
//
///* TEST LRU CACHE */
//  // cout << "LRU CACHE TEST: " << endl;
//  // vector<int> lruTest = {1, 2, 3, 2, 5, 3, 4, 5, 8, 9};
//  // LRUCache obj(4);
//  // // check processing
//  // vector<int> ans = obj.processRequests(lruTest);
//  // for (int i = 0; i < ans.size(); i++)
//  // {
//  //   cout << ans[i] << " ";
//  // }
//  // // check set-get LRU
//  // cout << endl << "setLRU-getLRU TEST: " << endl;
//  // vector<int> aux = obj.getLRU();
//  // // obj.setLRU(ans);
//
//  // for (auto it = aux.begin(); it != aux.end(); it++)
//  // {
//  //   cout << *it << " ";
//  // }
//  // cout << endl << endl;
//  // // check get-set cap
//  // obj.setCapacity(20);
//  // int a = obj.getSize(); int b = obj.getCapacity();
//  // cout << a << " " << b;
//  // cout << endl;
//
//
//
//
//  cout << endl << "END" << endl;
//  return 0;
//}
//
//
//
//
//
//// date enunturi clare, date deintrare clare, date de iesire fixe
//// modificam functia de getPrice si pentru Alimentar/NonFoodProduct, plus
//// calcul reducere Resigilat, Redus
//// static? stoc
//// operatii in functie de id - de cautare; eliminam string category