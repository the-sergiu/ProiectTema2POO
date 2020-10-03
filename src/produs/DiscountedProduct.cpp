#include "DiscountedProduct.h"
using namespace std;

DiscountedProduct::DiscountedProduct() : NonFoodProduct()
{
	this->discountPercentage = -1;
}

DiscountedProduct::DiscountedProduct(const string &categorie, int id, const string &producator, const string &nume, float pret, int garantieAni, int procentReducere, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate)
{
	this->discountPercentage = procentReducere;
}

DiscountedProduct::DiscountedProduct(const DiscountedProduct &produsRedus) : NonFoodProduct(produsRedus)
{
	this->discountPercentage = produsRedus.discountPercentage;
}

void DiscountedProduct::display()
{
	cout << "Product Redus" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent reducere : " << this->discountPercentage << endl
         << endl;
}

float DiscountedProduct::priceAfterDiscount() const
{
	return (100 - this->discountPercentage) * this->price;
}

float DiscountedProduct::getDiscountPercentage()
{
	return this->discountPercentage;
}

const DiscountedProduct &DiscountedProduct::operator=(const DiscountedProduct &a)
{
	this->name = a.name;
	this->producer = a.producer;
	this->category = a.category;
	this->id = a.id;
	this->quantity = a.quantity;
	this->yearsOfWarranty = a.yearsOfWarranty;
	this->price = a.price;
	this->discountPercentage = a.discountPercentage;

	return *this;
}

void DiscountedProduct::setDiscountPercentage(int procentReducere)
{
	this->discountPercentage = procentReducere;
}

string DiscountedProduct::getProductType()
{
	return "redus";
}

json DiscountedProduct::toJSON()
{
	return json(*this);
}
