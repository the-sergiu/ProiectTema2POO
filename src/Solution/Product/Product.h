#pragma once
#include <iostream>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

#define placeHolder "?"

class Product
{
protected:
    string name;
    int quantity;
    string category;
    int id;

public:
    // Virtuale
    virtual void display() = 0;
    virtual ~Product() = 0;
    virtual string getProductType() = 0;

    // Constructori
    Product();
    Product(const string &, int, const string &, int);
    Product(const Product &p);

    // Operator =
    const Product &operator=(const Product &);

    // Set
    void setCategory(const string &category);
    void setId(int);
    void setQuantity(int);
    void setName(const string &);

    // Get
    string &getCategory();
    int getQuantity();
    int getId();
    string &getName();

    // Metode Auxiliare
    bool checkQuantity(int);
    void decreaseQuantity(int);
    void increaseQuantity(int);

    // Administrative - NU MODIFICATI
    virtual json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Product, name, quantity, category, id)
};
