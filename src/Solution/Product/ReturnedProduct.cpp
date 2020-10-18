#include "ReturnedProduct.h"

ReturnedProduct::ReturnedProduct()
{
	throw("undefined");
}

ReturnedProduct::ReturnedProduct(const string &categorie, int id, const string &producator, const string &nume, float pret, int garantieAni, const string &motiv, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate)
{
	throw("undefined");
}

ReturnedProduct::ReturnedProduct(const ReturnedProduct &prodRet) : NonFoodProduct(prodRet)
{
	throw("undefined");
}

void ReturnedProduct::display()
{
	cout << "Product Returnat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Motiv : " << this->reason << endl
		 << endl;
}

const ReturnedProduct &ReturnedProduct::operator=(const ReturnedProduct &a)
{
	throw("undefined");
}

string &ReturnedProduct::getReason()
{
	throw("undefined");
}

void ReturnedProduct::setReason(string &reason)
{
	throw("undefined");
}

string ReturnedProduct::getProductType()
{
	throw("undefined");
}

json ReturnedProduct::toJSON()
{
	return json(*this);
}
