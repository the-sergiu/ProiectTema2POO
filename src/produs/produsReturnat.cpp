#include "produsReturnat.h"

ProdusReturnat::ProdusReturnat() {
	this->motiv = placeHolder;
}


ProdusReturnat::ProdusReturnat(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, const string& motiv, int cantitate)
	:ProdusNealimentar(categorie, id, producator, nume, pret, garantieAni, cantitate) {
	this->motiv = motiv;
}


void ProdusReturnat::afisare() {
	cout << "Produs Returnat" << endl;
  cout << "Nume Produs: " << this->nume << endl;
  cout << "Producator: " << this->producator << endl;
	cout << "Categorie: " << this->categorie << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->cantitate << endl;
	cout << "Garantie: " << this->garantieAni << " ani" << endl;
	cout << "Pret: " << this->pret << endl;
	cout << "Motiv : " << this->motiv << endl << endl;
}

const ProdusReturnat& ProdusReturnat::operator = (const ProdusReturnat& a){
  this->nume = a.nume;
  this->producator = a.producator;
  this->categorie = a.categorie;
  this->id = a.id;
  this->cantitate = a.cantitate;
  this->garantieAni = a.garantieAni;
  this->pret = a.pret;
  this->motiv = a.motiv;
  
  return *this;
}

string& ProdusReturnat::getMotiv() {
	return this->motiv;
}

void ProdusReturnat::setMotiv(string &motiv){
	this->motiv = motiv;
}

string ProdusReturnat::getProdusType(){
  return "returnat";
}

json ProdusReturnat::toJSON(){
	return json(*this);
}
