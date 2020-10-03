#include "Server.h"

using namespace std;

// Constructori + Destructori + Init
Server::Server()
{}

Server* Server::ServerInit()
{
  if(!instance)
  {
      instance = new Server;
  }
  
  return instance;
}

Server::~Server()
{
  if (instance != NULL)
      instance = NULL;
  if (!__ProductID__ProductObj__.empty())
    __ProductID__ProductObj__.clear();
  if (!__UserID__ProductsCart__.empty())
    __UserID__ProductsCart__.clear();
}

// SET
void Server::set__ProductID__ProductObj__()
{
  for (auto it = prod.begin(); it != prod.end(); ++it)
  {
      __ProductID__ProductObj__[(*it)->getId()] = *it;
  }
}



void Server::set__UserID__ProductsCart__()
{
  for (auto it = usr.begin(); it != usr.end(); ++it)
  {
      __UserID__ProductsCart__[(*it)->getUserID()] = new ShoppingCart;
  }
  //Testare initializare corecta map
  // for(auto const& x : this->__UserID__ProductsCart__){
  // cout<<x.first<<" - ";
  // x.second->display();
  // cout<<endl;
  // }
}


// GET
list<Product*>& Server::getProductsList()
{
  return this->prod;
}
list<User*>& Server::getUsersList()
{
  return this->usr;
}

unordered_map<int, Product*> Server::get__ProductID__ProductObj__()
{
  return this->__ProductID__ProductObj__;
}

unordered_map<int, ShoppingCart*> Server::get__UserID__ProductsCart__()
{
  return this->__UserID__ProductsCart__;
}


void Server::populateProducts(const json& input)
{
  prod = ObjectFactory::getProdusList(input["shoppingCart"]);
}

void Server::populateUsers(const json& input)
{
  usr = ObjectFactory::getUserList(input["useri"]);
}

// REQUESTS
void Server::requestAddProduct(int userID, int produsID, int cantitate)
{
  //Atentie verificare daca nu exista User sau Product cu id corect
  //Daca produsul cerut are cantitatea necesara
  if(__ProductID__ProductObj__[produsID]->checkQuantity(cantitate)) {
  //Ii scadem cantitatea
      __ProductID__ProductObj__[produsID]->decreaseQuantity(cantitate);
  //Adaugam produsul si cantitatea ceruta in cosul de shoppingCart al User-ului
      __UserID__ProductsCart__[userID]->addProduct(produsID, cantitate);
  }
  //Altfel nu aveam cantitatea necesara
  else cout<<endl<<"Produsul " << produsID << " nu are cantitatea necesara"<<endl;

  //Afisare cos de shoppingCart pentru User
  cout<<"Lista de shoppingCart pentru User "<<userID<<" este: "<<endl;
    __UserID__ProductsCart__[userID]->displayShoppingCart();
  
}

void Server::requestDeleteProduct(int userID, int produsID)
{
  //Crestem cantitatea de Product cu cea pe care User-ul o are in cos
    __ProductID__ProductObj__[produsID]->increaseQuantity(__UserID__ProductsCart__[userID]->getQuantity(produsID));
  //Stergem produsul din cosul de cumparaturi
    __UserID__ProductsCart__[userID]->deleteProduct(produsID);
}

void Server::requestModifyProduct(int userID, int produsID, int cantitateNoua)
{
  int diferenta = __UserID__ProductsCart__[userID]->getQuantity(produsID) - cantitateNoua;

  //Daca cantitatea ceruta este mai mica decat este acum in cos
  if(diferenta > 0)
  {
    //Creste cantitatea disponibila a produslui
      __ProductID__ProductObj__[produsID]->increaseQuantity(diferenta);
    //Modificam cantitatea din cos cu cea noua
      __UserID__ProductsCart__[userID]->addProduct(produsID, cantitateNoua);
  }

  //Daca cantitatea ceruta este mai mare decat este acum in cos
  else if(diferenta < 0)
  {
    //Verifica daca e disponibila difereta de quantity
    if(__ProductID__ProductObj__[produsID]->checkQuantity(-diferenta)) {
    //Ii scadem cantitatea
        __ProductID__ProductObj__[produsID]->decreaseQuantity(-diferenta);
    //Modificam cantitatea din cos cu cea noua
        __UserID__ProductsCart__[userID]->addProduct(produsID, cantitateNoua);
    }
  }

  //Altfel cantitatea este aceeasi si nu se modifica
  else cout<<endl<<"Cantitatea nu se modifica"<<endl;

}



