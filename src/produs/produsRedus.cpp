#include "produsRedus.h"
using namespace std;

ProdusRedus::ProdusRedus() : ProdusNealimentar(){
	this->procentReducere = -1;
}

ProdusRedus::ProdusRedus(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, int procentReducere, int cantitate)
	:ProdusNealimentar(categorie, id, producator, nume, pret, garantieAni, cantitate) {
	this->procentReducere = procentReducere;
}

void ProdusRedus::afisare()  {
	cout << "Produs Redus" << endl;
  cout << "Nume Produs: " << this->nume << endl;
  cout << "Producator: " << this->producator << endl;
	cout << "Categorie: " << this->categorie << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->cantitate << endl;
	cout << "Garantie: " << this->garantieAni << " ani" << endl;
	cout << "Pret: " << this->pret << endl;
	cout << "Procent reducere : " << this->procentReducere << endl << endl;
}


float ProdusRedus::pretDupaReducere() const {
	return (100 - this->procentReducere) * this->pret;
}

float ProdusRedus::getProcentReducere() {
	return this->procentReducere;
}

const ProdusRedus& ProdusRedus::operator = (const ProdusRedus& a){
  this->nume = a.nume;
  this->producator = a.producator;
  this->categorie = a.categorie;
  this->id = a.id;
  this->cantitate = a.cantitate;
  this->garantieAni = a.garantieAni;
  this->pret = a.pret;
  this->procentReducere = a.procentReducere;

  return *this;
}

void ProdusRedus::setProcentReducere(int procentReducere) {
	this->procentReducere = procentReducere;
}

json ProdusRedus::toJSON(){
	return json(*this);
}
