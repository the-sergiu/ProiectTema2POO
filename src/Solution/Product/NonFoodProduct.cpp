#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct()
{
	throw("undefined");
}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
	throw("undefined");
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	throw("undefined");
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}

// SET-eri
void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	throw("undefined");
}

void NonFoodProduct::setPret(float price)
{
	throw("undefined");
}

void NonFoodProduct::setProducator(const string &producer)
{
	throw("undefined");
}

//GET-eri
int NonFoodProduct::getYearsOfWarranty()
{
	throw("undefined");
}

float NonFoodProduct::getPrice()
{
	throw("undefined");
}

string &NonFoodProduct::getProducer()
{
	throw("undefined");
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	throw("undefined");
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	throw("undefined");
}

string NonFoodProduct::getProductType()
{
	throw("undefined");
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}