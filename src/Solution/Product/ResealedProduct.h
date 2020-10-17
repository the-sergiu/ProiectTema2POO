#pragma once
#include "DiscountedProduct.h"
#include "ReturnedProduct.h"

class ResealedProduct : public DiscountedProduct, public ReturnedProduct
{
private:
    int wearPercentage;
public:
    ResealedProduct();
    ResealedProduct(const string&, int, const string&, const string&, float, int, int, const string&, int, int);
    ResealedProduct(const ResealedProduct&);


    void display();
    string getProductType();


    //SET-ERI
    void setWearPercentage(int);
    
    //GET-ERI
    float getWearPercentage();

    json toJSON();

    const ResealedProduct& operator = (const ResealedProduct&);

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ResealedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, reason, discountPercentage, wearPercentage)
};

