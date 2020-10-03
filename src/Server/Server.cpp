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
bool Server::requestAddProduct(int userID, int productID, int cantitate)
{
  //Verificare daca nu exista User sau Product cu id corect
  auto it_user = __UserID__ProductsCart__.find(userID);

  if (it_user == __UserID__ProductsCart__.end())
    return false;

  auto it_prod = __ProductID__ProductObj__.find(productID);

  if (it_prod == __ProductID__ProductObj__.end())
    return false;

  //Returnam cosul de produse al user-ului
  unordered_map<int,int> cart = __UserID__ProductsCart__[userID]->getShoppingCart();

  //Cautam produsul in el
  auto it_request = cart.find(productID);

  //Daca nu e, se adauga
  if (it_request == cart.end()){
  cout<<endl<<"Se adauga cantitatea";
  //Daca produsul cerut are cantitatea necesara
  if(__ProductID__ProductObj__[productID]->checkQuantity(cantitate)) {
  //Ii scadem cantitatea
      __ProductID__ProductObj__[productID]->decreaseQuantity(cantitate);
  //Adaugam produsul si cantitatea ceruta in cosul de shoppingCart al User-ului
      __UserID__ProductsCart__[userID]->addProduct(productID, cantitate);
      return true;
  }
  //Altfel nu aveam cantitatea necesara
  else{
    cout<<endl<<"Produsul " << productID << " nu are cantitatea necesara"<<endl;
    return false;
  }
  }

  //Daca e, se modifica cantitatea care e deja in cos
  else{
    cout<<endl<<"Se modifica cantitatea";
    int diferenta = __UserID__ProductsCart__[userID]->getQuantity(productID) - cantitate;

  //Daca cantitatea ceruta este mai mica decat este acum in cos
  if(diferenta > 0)
  {
    //Creste cantitatea disponibila a produslui
      __ProductID__ProductObj__[productID]->increaseQuantity(diferenta);
    //Modificam cantitatea din cos cu cea noua
      __UserID__ProductsCart__[userID]->addProduct(productID, cantitate);
      return true;
  }

  //Daca cantitatea ceruta este mai mare decat este acum in cos
  else if(diferenta < 0)
  {
    //Verifica daca e disponibila diferenta de cantitate
    if(__ProductID__ProductObj__[productID]->checkQuantity(-diferenta)) {
    //Ii scadem cantitatea
        __ProductID__ProductObj__[productID]->decreaseQuantity(-diferenta);
    //Modificam cantitatea din cos cu cea noua
        __UserID__ProductsCart__[userID]->addProduct(productID, cantitate);
    return true;
    }

    //Daca nu e disponibila diferenta de cantitate
    else return false;
  }

  //Altfel cantitatea este aceeasi si nu se modifica
  else{
    cout<<endl<<"Cantitatea nu se modifica"<<endl;
    return true;
  }
  }  
}

bool Server::requestDeleteProduct(int userID, int productID)
{
  //Crestem cantitatea de Product cu cea pe care User-ul o are in cos
    __ProductID__ProductObj__[productID]->increaseQuantity(__UserID__ProductsCart__[userID]->getQuantity(productID));
  //Stergem produsul din cosul de cumparaturi
    __UserID__ProductsCart__[userID]->deleteProduct(productID);
}
