#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct() {
  this->producer = placeHolder;
	this->yearsOfWarranty = -1;
	this->price = -1;
}

NonFoodProduct::NonFoodProduct(const string& category, int id, const string& producer, const string& name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
  this->producer = producer;
	this->yearsOfWarranty = yearsOfWarranty;
	this->price = price;
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	this->producer = pn.producer;
	this->price = pn.price;
	this->yearsOfWarranty = pn.yearsOfWarranty;
}

void NonFoodProduct::display() {
  cout << "Product Nealimentar" << endl;
  cout << "Nume Product: " << this->name << endl;
  cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl << endl;
}

// SET-eri
void NonFoodProduct::setYearsOfWarranty(int garantieAni) {
	this->yearsOfWarranty = garantieAni;
}

void NonFoodProduct::setPrice(float price) {
	this->price = price;
}

void NonFoodProduct::setProducer(const string & producer){
  this->producer = producer;
}

//GET-eri
int NonFoodProduct::getYearsOfWarranty() {
	return this->yearsOfWarranty;
}

float NonFoodProduct::getPrice(){
	return this->price;
}

string& NonFoodProduct::getProducer(){
  return this->producer;
}

bool NonFoodProduct::operator == (const NonFoodProduct& obj)const {
	return (this->price == obj.price) ? true : false;
}

const NonFoodProduct& NonFoodProduct::operator = (const NonFoodProduct& a){
  this->name = a.name;
  this->producer = a.producer;
  this->category = a.category;
  this->id = a.id;
  this->quantity = a.quantity;
  this->yearsOfWarranty = a.yearsOfWarranty;
  this->price = a.price;
  return *this;
}

string NonFoodProduct::getProductType(){
  return "nealimentar";
}

json NonFoodProduct::toJSON(){
	return json(*this);
}