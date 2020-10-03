#pragma once
#include "NonFoodProduct.h"

class DiscountedProduct : virtual public NonFoodProduct
{
protected:
    int discountPercentage;

public:
    // Constructori
    DiscountedProduct();
    DiscountedProduct(const string &, int, const string &, const string &, float, int, int, int);
    DiscountedProduct(const DiscountedProduct &);

    // Operator =
    const DiscountedProduct &operator=(const DiscountedProduct &);

    // Set
    void setDiscountPercentage(int);
    // Get
    float getDiscountPercentage();

    // Metode Auxiliare
    void display();
    float priceAfterDiscount() const;

    // Administrative - NU MODIFICATI
    string getProductType();
    json toJSON();

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(DiscountedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, discountPercentage)
};
