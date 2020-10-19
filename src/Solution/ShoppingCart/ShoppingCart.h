#pragma once
#include <iostream>
#include <string>
#include <map>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;


class ShoppingCart
{
  private:
    map<int, int> shoppingCart;
    string payMethod;

  public:
    ShoppingCart();
    ShoppingCart(const string&);
    string& getPayMethod();
    void setPayMethod(const string &payMethod);
    int getQuantity(int);
    void addProduct(int, int);
    void raiseQuantity(int, int);
    void lowerQuantity(int, int);
    void deleteProduct(int);
    map<int,int>& getShoppingCart();
    void displayShoppingCart();
    json toJSON();
    
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShoppingCart, shoppingCart, payMethod)
};