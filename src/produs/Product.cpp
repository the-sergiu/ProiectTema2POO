#include "Product.h"
using namespace std;

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
  cout << endl
       << "Cantitatea produsului este " << this->quantity << endl;
  if (this->quantity >= requestedQuantity)
    return true;
  else
    return false;
}

Product::Product(const string &category, int id, const string &name, int quantity)
{
  this->category = category;
  this->id = id;
  this->name = name;
  this->quantity = quantity;
}

Product::Product(const Product &p)
{
  this->category = p.category;
  this->id = p.id;
  this->name = p.name;
  this->quantity = p.quantity;
}

Product::Product()
{
  this->category = placeHolder;
  this->id = -1;
  this->name = placeHolder;
  this->quantity = -1;
}

void Product::decreaseQuantity(int requestedQuantity)
{
  this->quantity -= requestedQuantity;
}

void Product::increaseQuantity(int requestedQuantity)
{
  this->quantity += requestedQuantity;
}

void Product::setCategory(const string &category)
{
  this->category = category;
}

void Product::setId(int id)
{
  this->id = id;
}

void Product::setQuantity(int quantity)
{
  this->quantity = quantity;
}

void Product::setName(const string &)
{
  this->name = name;
}

string &Product::getCategory()
{
  return this->category;
}

int Product::getQuantity()
{
  return this->quantity;
}

int Product::getId()
{
  return this->id;
}

string &Product::getName()
{
  return this->name;
}

const Product &Product::operator=(const Product &a)
{
  this->name = a.name;
  this->category = a.category;
  this->id = a.id;
  this->quantity = a.quantity;

  return *this;
}

json Product::toJSON()
{
  return json(*this);
}
