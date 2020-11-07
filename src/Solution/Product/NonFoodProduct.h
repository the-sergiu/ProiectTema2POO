#pragma once
#include "Product.h"

class NonFoodProduct : public Product
{
protected:
  string producer;
  int yearsOfWarranty;
  float price;

public:
  // Constructori
  NonFoodProduct();
  NonFoodProduct(const string &, int, const string &, const string &, float, int, int);
  NonFoodProduct(const NonFoodProduct &pn);

  // Operator =
  const NonFoodProduct &operator=(const NonFoodProduct &);
  /*
   * @param seteaza campul yearsOfWarranty
   */
  void setYearsOfWarranty(int);
  /*
   * @param seteaza campul price (pret)
   */
  void setPrice(float);
  /*
   * @param seteaza campul producer (producator)
   */
  void setProducer(const string &);
  /*
   * @return warranty (garantie)
   */
  int getYearsOfWarranty();
  /*
   * @return campul price (pret)
   */
  float getPrice();
  /*
   * @return campul producer (producator)
   */
  string &getProducer();
  /*
   * @return tipul produsului (nu este un camp)
   */
  string getProductType();

  // Operator ==
  bool operator==(const NonFoodProduct &) const;

  /*
  *     ADMINISTRATIV - NU MODIFICATI
  */
  json toJSON();
  void display();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(NonFoodProduct, name, quantity, category, id, producer, yearsOfWarranty, price)
};
