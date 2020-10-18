#include "Product.h"
using namespace std;

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
	throw("undefined");
}

Product::Product(const string &category, int id, const string &name, int quantity)
{
	throw("undefined");
}

Product::Product(const Product &p)
{
	throw("undefined");
}

Product::Product()
{
	throw("undefined");
}

void Product::decreaseQuantity(int requestedQuantity)
{
	throw("undefined");
}

void Product::increaseQuantity(int requestedQuantity)
{
	throw("undefined");
}

void Product::setCategory(const string &category)
{
	throw("undefined");
}

void Product::setId(int id)
{
	throw("undefined");
}

void Product::setQuantity(int quantity)
{
	throw("undefined");
}

void Product::setName(const string &)
{
	throw("undefined");
}

string &Product::getCategory()
{
	throw("undefined");
}

int Product::getQuantity()
{
	throw("undefined");
}

int Product::getId()
{
	throw("undefined");
}

string &Product::getName()
{
	throw("undefined");
}

const Product &Product::operator=(const Product &a)
{
	throw("undefined");
}

json Product::toJSON()
{
	return json(*this);
}
