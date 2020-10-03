#pragma once
#include "DiscountedProduct.h"
#include "produsReturnat.h"

class ProdusResigilat : public DiscountedProduct, public ProdusReturnat
{
private:
    int procentUzura;
public:
    ProdusResigilat();
    ProdusResigilat(const string&, int, const string&, const string&, float, int, int, const string&, int, int);
    ProdusResigilat(const ProdusResigilat&);


    void display();
    string getProductType();


    //SET-ERI
    void setProcentUzura(int);
    
    //GET-ERI
    float getProcentUzura();

    json toJSON();

    const ProdusResigilat& operator = (const ProdusResigilat&);

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ProdusResigilat, name, quantity, category, id, producer, yearsOfWarranty, price, motiv, discountPercentage, procentUzura)
};

