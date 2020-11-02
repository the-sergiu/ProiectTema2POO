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
    void setPayMethod(const string &);
    int getQuantity(int);
    /*
      * @param id id-ul produsului de adaugat in cos
      * @param quantity cantiatatea de produs de adaugat in cos
      */
    void addProduct(int id, int quantity);
    /*
      * @param id id-ul produsului pentru care se creste cantitatea din cos
      * @param quantity cantiatatea care se adauga
      */
    void raiseQuantity(int id, int quantity);
    /*
      * @param id id-ul produsului pentru care se scade cantitatea din cos
      * @param quantity cantitatea care se scade
      */
    void lowerQuantity(int id, int quantity);
    /*
      * @param productID id-ul produsului de scos din cos
      */
    void deleteProduct(int productID);
    /*
      * @return referinta catre shoppingCart
      */
    map<int,int>& getShoppingCart();
    
    void displayShoppingCart();

    // Administrativ - NU MODIFICATI
    json toJSON();
    
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShoppingCart, shoppingCart, payMethod)
};