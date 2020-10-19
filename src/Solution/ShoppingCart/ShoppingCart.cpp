#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	throw("undefined");
}

string &ShoppingCart::getPayMethod()
{
	throw("undefined");
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	throw("undefined");
}

void ShoppingCart::addProduct(int id, int quantity)
{
	throw("undefined");
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	throw("undefined");
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	throw("undefined");
}

int ShoppingCart::getQuantity(int productID)
{
	throw("undefined");
}

void ShoppingCart::deleteProduct(int productID)
{
	throw("undefined");
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	throw("undefined");
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}