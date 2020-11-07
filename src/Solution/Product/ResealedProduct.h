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

    /*
     * @return tipul produsului (nu este camp)
     */
    string getProductType();
    /*
     * @param seteaza campul wearPercentage (uzura)
     */
    void setWearPercentage(int);
    /*
     * @return campul wearPercentage (uzura)
     */
    float getWearPercentage();

    const ResealedProduct& operator = (const ResealedProduct&);
    /*
     *     ADMINISTRATIV - NU MODIFICATI
     */
    json toJSON();
    void display();
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ResealedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, reason, discountPercentage, wearPercentage)
};

