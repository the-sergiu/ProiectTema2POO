#include "produsReturnat.h"

ProdusReturnat::ProdusReturnat() : ProdusNealimentar(){
	this->motiv = placeHolder;
}


ProdusReturnat::ProdusReturnat(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, const string& motiv, int cantitate)
	:ProdusNealimentar(categorie, id, producator, nume, pret, garantieAni, cantitate) {
	this->motiv = motiv;
}


void ProdusReturnat::afisare() {
	ProdusNealimentar::afisare();
  cout << "Produs Returnat" << endl;
	cout << "Motiv : " << this->motiv << endl;
}

string& ProdusReturnat::getMotiv() {
	return this->motiv;
}

void ProdusReturnat::setMotiv(string &motiv){
	this->motiv = motiv;
}

json ProdusReturnat::toJSON(){
	return json(*this);
}