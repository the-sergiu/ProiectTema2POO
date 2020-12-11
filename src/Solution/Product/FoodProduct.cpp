#include "FoodProduct.h"

FoodProduct::FoodProduct()
{
	throw("undefined");
}

FoodProduct::FoodProduct(const string &categorie, int id, const string &nume, float leiPerKg, const string &taraOrigine, int cantitate) : Product(categorie, id, nume, cantitate)
{
	throw("undefined");
}

FoodProduct::FoodProduct(const FoodProduct &pa) : Product(pa)
{
	throw("undefined");
}

void FoodProduct::setLeiPerKg(float leiPerKg)
{
	throw("undefined");
}

void FoodProduct::setCountryOfOrigin(const string &countryOfOrigin)
{
	throw("undefined");
}

float FoodProduct::getLeiPerKg()
{
	throw("undefined");
}

string &FoodProduct::getCountryOfOrigin()
{
	throw("undefined");
}

const FoodProduct &FoodProduct::operator=(const FoodProduct &a)
{
	throw("undefined");
}

string FoodProduct::getProductType()
{
	throw("undefined");
}

json FoodProduct::toJSON()
{
	return json(*this);
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