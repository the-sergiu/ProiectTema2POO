#include "produsNealimentar.h"

ProdusNealimentar::ProdusNealimentar() {
  this->producator = placeHolder;
	this->garantieAni = -1;
	this->pret = -1;
}

ProdusNealimentar::ProdusNealimentar(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, int cantitate) : Produs(categorie, id, nume, cantitate){
  this->producator = producator;
	this->garantieAni = garantieAni;
	this->pret = pret;
}

void ProdusNealimentar::afisare(){
  cout << "Produs Nealimentar" << endl;
  cout << "Nume Produs: " << this->nume << endl;
  cout << "Producator: " << this->producator << endl;
	cout << "Categorie: " << this->categorie << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->cantitate << endl;
	cout << "Garantie: " << this->garantieAni << " ani" << endl;
	cout << "Pret: " << this->pret << endl;
}

// SET-eri
void ProdusNealimentar::setGarantieAni(int garantieAni) {
	this->garantieAni = garantieAni;
}

void ProdusNealimentar::setPret(float pret) {
	this->pret = pret;
}

void ProdusNealimentar::setProducator(const string & producator){
  this->producator = producator;
}

//GET-eri
int ProdusNealimentar::getGarantieAni() {
	return this->garantieAni;
}

float ProdusNealimentar::getPret(){
	return this->pret;
}

string& ProdusNealimentar::getProducator(){
  return this->producator;
}

bool ProdusNealimentar::operator == (const ProdusNealimentar& obj)const {
	return (this->pret == obj.pret) ? true : false;
}

json ProdusNealimentar::toJSON(){
	return json(*this);
}