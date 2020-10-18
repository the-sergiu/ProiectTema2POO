#pragma once
#include <string>
#include <list>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "../Product/ResealedProduct.h"
#include "../Product/FoodProduct.h"
#include "../User/PremiumUser.h"
#include "../User/BasicUser.h"
#include "../ShoppingCart/ShoppingCart.h"
#include "../../utils/objectFactory/objectFactory.h"

using namespace std;

class Server
{
  private:
    
    static Server *instance;

    int usersCapacity;
    list<User*> usr;
    list<Product*> prod;

    // map ProductID : Products
    map<int, Product*> __ProductID__ProductObj__;

    // map UserID : ProductsCart
    map<int, ShoppingCart*> __UserID__ProductsCart__;


    // Singleton
    Server();
  public:
    static Server* GetInstance();
    ~Server();

    map<int, Product*> get__ProductID__ProductObj__();
    map<int, ShoppingCart*> get__UserID__ProductsCart__();

    void populateProducts(const json&);
    void populateUsers(const json&);

    void set__ProductID__ProductObj__();
    void set__UserID__ProductsCart__();


    list<Product*>& getProductsList();
    list<User*>& getUsersList();

    bool requestAddProduct(int, int, int);
    bool requestDeleteProduct(int, int, int);



};