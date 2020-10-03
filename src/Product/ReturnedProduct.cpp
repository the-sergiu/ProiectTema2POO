#include "ReturnedProduct.h"

ReturnedProduct::ReturnedProduct() {
	this->reason = placeHolder;
}


ReturnedProduct::ReturnedProduct(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, const string& motiv, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate) {
	this->reason = motiv;
}

ReturnedProduct::ReturnedProduct(const ReturnedProduct &prodRet) : NonFoodProduct(prodRet)
{
  this->reason = prodRet.reason;
}

void ReturnedProduct::display() {
	cout << "Product Returnat" << endl;
  cout << "Nume Product: " << this->name << endl;
  cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Motiv : " << this->reason << endl << endl;
}

const ReturnedProduct& ReturnedProduct::operator = (const ReturnedProduct& a){
  this->name = a.name;
  this->producer = a.producer;
  this->category = a.category;
  this->id = a.id;
  this->quantity = a.quantity;
  this->yearsOfWarranty = a.yearsOfWarranty;
  this->price = a.price;
  this->reason = a.reason;
  
  return *this;
}

string& ReturnedProduct::getReason() {
	return this->reason;
}

void ReturnedProduct::setReason(string & reason){
	this->reason = reason;
}

string ReturnedProduct::getProductType(){
  return "returnat";
}

json ReturnedProduct::toJSON(){
	return json(*this);
}
