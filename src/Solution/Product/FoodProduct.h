#pragma once
#include "Product.h"
#include <string>

class FoodProduct : public Product
{
protected:
    float leiPerKg;
    string countryOfOrigin;

public:
    // Constructori
    FoodProduct();
    FoodProduct(const string &, int, const string &, float, const string &, int);
    FoodProduct(const FoodProduct &);

    // Operator =
    const FoodProduct &operator=(const FoodProduct &);

    // Set
    void setLeiPerKg(float);
    void setCountryOfOrigin(const string &countryOfOrigin);

    // Get
    float getLeiPerKg();
    string &getCountryOfOrigin();

    // Metode Auxiliare
    void display();

    // Operatori
    bool operator==(const FoodProduct &) const;
    bool operator<(const FoodProduct &) const;
    bool operator>(const FoodProduct &) const;

    // Administrative - NU MODIFICATI
    string getProductType();
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(FoodProduct, name, quantity, category, id, leiPerKg, countryOfOrigin)
};
