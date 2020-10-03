#include "produsResigilat.h"

using namespace std;

ProdusResigilat::ProdusResigilat()
{
	this->procentUzura = -1;
}

ProdusResigilat::ProdusResigilat(const string &categorie, int id, const string &producator, const string &nume, float pret, int garantieAni, int procentReducere, const string &motiv, int procentUzura, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate)
{
	DiscountedProduct(categorie, id, producator, nume, pret, garantieAni, procentReducere, cantitate),
		ProdusReturnat(categorie, id, producator, nume, pret, garantieAni, motiv, cantitate),
		this->procentUzura = procentUzura;
}

ProdusResigilat::ProdusResigilat(const ProdusResigilat &pr) : NonFoodProduct(pr), DiscountedProduct(pr), ProdusReturnat(pr)
{
	this->procentUzura = pr.procentUzura;
}

void ProdusResigilat::display()
{
	cout << "Product Resigilat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent Reducere: " << this->discountPercentage << endl;
	cout << "Procent Uzura: " << this->procentUzura << endl;
	cout << "Motiv retur: " << this->motiv << endl
		 << endl;
}

void ProdusResigilat::setProcentUzura(int procentUzura)
{
	this->procentUzura = procentUzura;
}

float ProdusResigilat::getProcentUzura()
{
	return this->procentUzura;
}

const ProdusResigilat &ProdusResigilat::operator=(const ProdusResigilat &a)
{
	this->name = a.name;
	this->producer = a.producer;
	this->category = a.category;
	this->id = a.id;
	this->quantity = a.quantity;
	this->yearsOfWarranty = a.yearsOfWarranty;
	this->price = a.price;
	this->discountPercentage = a.discountPercentage;
	this->motiv = a.motiv;
	this->procentUzura = a.procentUzura;

	return *this;
}

string ProdusResigilat::getProductType()
{
	return "resigilat";
}

json ProdusResigilat::toJSON()
{
	return json(*this);
}
