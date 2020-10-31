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

  if (!__UserID__ProductsCart__.empty())
    __UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
  for (auto it = usr.begin(); it != usr.end(); ++it)
  {
      __UserID__ProductsCart__[(*it)->getUserID()] = new ShoppingCart();
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

map<int, ShoppingCart*> Server::get__UserID__ProductsCart__()
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
bool Server::requestAddProduct(int userID, int productID, int quantity)
{
  //Daca cantitatea este <= 0
  if (quantity <= 0)
      return false;

  //Verificare daca nu exista User sau Product cu id corect
  auto it_user = __UserID__ProductsCart__.find(userID);
  if (it_user == __UserID__ProductsCart__.end())
      return false;

  auto it_prod = std::find_if(prod.begin(), prod.end(), [productID](Product *const &p) {
    return (p->getId() == productID);
  });

  if (it_prod == prod.end()) {
    return false;
  }

  auto product = *it_prod;

  //Returnam cosul de produse al user-ului
  map<int,int> cart = __UserID__ProductsCart__[userID]->getShoppingCart();

  //Cautam produsul in el
  auto it_request = cart.find(productID);

  //Daca nu e, se adauga
  if (it_request == cart.end()){
    //Daca produsul cerut are cantitatea necesara
    if(product->checkQuantity(quantity)) {
    //Ii scadem cantitatea
        product->decreaseQuantity(quantity);
    //Adaugam produsul si cantitatea ceruta in cosul de shoppingCart al User-ului
        __UserID__ProductsCart__[userID]->addProduct(productID, quantity);
        return true;
    }
    //Altfel nu aveam cantitatea necesara
    else return false;
  }

  //Daca e, se modifica cantitatea care e deja in cos
  else{
    if(product->checkQuantity(quantity)) {
    //Ii scadem cantitatea
        product->decreaseQuantity(quantity);
    //Adaugam produsul si cantitatea ceruta in cosul de shoppingCart al User-ului
        __UserID__ProductsCart__[userID]->raiseQuantity(productID, quantity);
        return true;
    }
    //Altfel nu aveam cantitatea necesara
    else return false;
  }
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
  //Verificam cantitate >= 0
  if (quantity <= 0 )
    return false;

  //Verificare daca nu exista User sau Product cu id corect
  auto it_user = __UserID__ProductsCart__.find(userID);
  if (it_user == __UserID__ProductsCart__.end())
    return false;

  auto it_prod = std::find_if(prod.begin(), prod.end(), [productID](Product *const &p) {
    return (p->getId() == productID);
  });

  if (it_prod == prod.end())
  {
    return false;
  }

  auto product = *it_prod;

  //Returnam cosul de produse al user-ului
  map<int,int> cart = __UserID__ProductsCart__[userID]->getShoppingCart();

  //Cautam produsul in el
  auto it_request = cart.find(productID);

  //Daca nu e in cos, nu avem cum sa il stergem
  if (it_request == cart.end())
    return false;

  else{
    //Daca cantitatea pe care vrem sa o stergem >= cu cea din cos
    if (quantity >= __UserID__ProductsCart__[userID]->getQuantity(productID)){
    //Crestem cantitatea de Product cu cea pe care User-ul o are in cos
    product->increaseQuantity(__UserID__ProductsCart__[userID]->getQuantity(productID));
    //Stergem produsul din cosul de cumparaturi
    __UserID__ProductsCart__[userID]->deleteProduct(productID);
    }

    //Altfel, stergem cat dorim
    else{
      product->increaseQuantity(quantity);
      __UserID__ProductsCart__[userID]->lowerQuantity(productID, quantity);
    }

    return true;
  }
}
