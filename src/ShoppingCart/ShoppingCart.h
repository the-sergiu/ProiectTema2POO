#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "../src/json.hpp"

using namespace std;
using json = nlohmann::json;


class ShoppingCart
{
  private:
    unordered_map<int, int> shoppingCart;
    string payMethod;

  public:
    ShoppingCart();
    ShoppingCart(const string&);
    string& getPayMethod();
    void setPayMethod(const string &payMethod);
    int getQuantity(int);
    void addProduct(int, int);
    void deleteProduct(int);
    unordered_map<int,int>& getShoppingCart();
    void displayShoppingCart();
    json toJSON();
    
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShoppingCart, shoppingCart, payMethod)
};