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

  // Set
  void setYearsOfWarranty(int);
  void setPret(float);
  void setProducator(const string &);

  // Get
  int getYearsOfWarranty();
  float getPrice();
  string &getProducer();

  // Metode Auxiliare
  void display();
  string getProductType();

  // Operator ==
  bool operator==(const NonFoodProduct &) const;

  // Administrative - NU MODIFICATI
  json toJSON();

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(NonFoodProduct, name, quantity, category, id, producer, yearsOfWarranty, price)
};
