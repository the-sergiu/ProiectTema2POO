#include "produsReturnat.h"

ProdusReturnat::ProdusReturnat() {
	this->motiv = placeHolder;
}


ProdusReturnat::ProdusReturnat(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, const string& motiv, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate) {
	this->motiv = motiv;
}

ProdusReturnat::ProdusReturnat(const ProdusReturnat &prodRet) : NonFoodProduct(prodRet)
{
  this->motiv = prodRet.motiv;
}

void ProdusReturnat::display() {
	cout << "Product Returnat" << endl;
  cout << "Nume Product: " << this->name << endl;
  cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Motiv : " << this->motiv << endl << endl;
}

const ProdusReturnat& ProdusReturnat::operator = (const ProdusReturnat& a){
  this->name = a.name;
  this->producer = a.producer;
  this->category = a.category;
  this->id = a.id;
  this->quantity = a.quantity;
  this->yearsOfWarranty = a.yearsOfWarranty;
  this->price = a.price;
  this->motiv = a.motiv;
  
  return *this;
}

string& ProdusReturnat::getMotiv() {
	return this->motiv;
}

void ProdusReturnat::setMotiv(string &motiv){
	this->motiv = motiv;
}

string ProdusReturnat::getProductType(){
  return "returnat";
}

json ProdusReturnat::toJSON(){
	return json(*this);
}
