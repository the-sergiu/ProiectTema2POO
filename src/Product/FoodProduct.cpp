#include "FoodProduct.h"

FoodProduct::FoodProduct()
{
	this->leiPerKg = -1;
	this->countryOfOrigin = placeHolder;
}

FoodProduct::FoodProduct(const string &categorie, int id, const string &nume, float leiPerKg, const string &taraOrigine, int cantitate) : Product(categorie, id, nume, cantitate)
{
	this->leiPerKg = leiPerKg;
	this->countryOfOrigin = taraOrigine;
}

FoodProduct::FoodProduct(const FoodProduct &pa) : Product(pa)
{
	this->leiPerKg = pa.leiPerKg;
	this->countryOfOrigin = pa.countryOfOrigin;
}

void FoodProduct::display()
{
	cout << "Product alimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Categorie : " << this->category << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->quantity << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->countryOfOrigin << endl
         << endl;
}
// SET-eri
void FoodProduct::setLeiPerKg(float leiPerKg)
{
	this->leiPerKg = leiPerKg;
}

void FoodProduct::setCountryOfOrigin(const string &countryOfOrigin)
{
	this->countryOfOrigin = countryOfOrigin;
}

// GET-eri
float FoodProduct::getLeiPerKg()
{
	return this->leiPerKg;
}

string &FoodProduct::getCountryOfOrigin()
{
	return this->countryOfOrigin;
}

// OPERATORI
bool FoodProduct::operator==(const FoodProduct &obj) const
{
	return (this->leiPerKg == obj.leiPerKg) ? true : false;
}

bool FoodProduct::operator<(const FoodProduct &obj) const
{
	return (this->leiPerKg < obj.leiPerKg) ? true : false;
}

bool FoodProduct::operator>(const FoodProduct &obj) const
{
	return (this->leiPerKg > obj.leiPerKg) ? true : false;
}

const FoodProduct &FoodProduct::operator=(const FoodProduct &a)
{
	this->name = a.name;
	this->category = a.category;
	this->id = a.id;
	this->quantity = a.quantity;
	this->leiPerKg = a.leiPerKg;
	this->countryOfOrigin = a.countryOfOrigin;
	return *this;
}

string FoodProduct::getProductType()
{
	return "alimentar";
}

json FoodProduct::toJSON()
{
	return json(*this);
}
