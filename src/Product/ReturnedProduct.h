#pragma once
#include "NonFoodProduct.h"

class ReturnedProduct : virtual public NonFoodProduct
{
protected:
    string reason;

public:
    // Constructori
    ReturnedProduct();
    ReturnedProduct(const string &, int, const string &, const string &, float, int, const string &, int);
    ReturnedProduct(const ReturnedProduct &);

    // Operator =
    const ReturnedProduct &operator=(const ReturnedProduct &);

    // Get
    string &getReason();

    // Set
    void setReason(string &);

    // Metode Auxiliare
    void display();
    string getProductType();

    // Administrativ - NU MODIFICATI
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ReturnedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, reason)
};
