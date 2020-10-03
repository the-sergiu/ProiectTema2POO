#pragma once
#include "NonFoodProduct.h"

class ProdusReturnat : virtual public NonFoodProduct
{
protected:
    string motiv;

public:
    // Constructori
    ProdusReturnat();
    ProdusReturnat(const string &, int, const string &, const string &, float, int, const string &, int);
    ProdusReturnat(const ProdusReturnat &);

    // Operator =
    const ProdusReturnat &operator=(const ProdusReturnat &);

    // Set
    string &getMotiv();

    // Get
    void setMotiv(string &);

    // Metode Auxiliare
    void display();
    string getProductType();

    // Administrativ - NU MODIFICATI
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusReturnat, name, quantity, category, id, producer, yearsOfWarranty, price, motiv)
};
