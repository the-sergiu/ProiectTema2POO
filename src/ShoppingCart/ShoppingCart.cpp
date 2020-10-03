#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
  this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string& payMethod)
{
  this->payMethod = payMethod;
}

string& ShoppingCart::getPayMethod()
{
  return this->payMethod;
}

void ShoppingCart::setPayMethod(const string& payMethod)
{
  this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
    shoppingCart[id] = quantity;
}

int ShoppingCart::getQuantity(int productID)
{
  return this->shoppingCart[productID];
}

void ShoppingCart::deleteProduct(int productID)
{
  this->shoppingCart.erase(productID);
}

unordered_map<int, int>& ShoppingCart::getShoppingCart() {
  return this->shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
  if (this->shoppingCart.empty()) {
    cout << "Cosul de shoppingCart este gol";
  }
  else
  {
    cout<<"ProdusID:    ///   Cantitate:"<<endl;

    for(auto const& x : this->shoppingCart)
      cout<<x.first<<" "<<x.second<<endl;
  }

}

json ShoppingCart::toJSON()
{
  return json(*this);
}