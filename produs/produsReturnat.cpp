#include "produsReturnat.h"

ProdusReturnat::ProdusReturnat() : ProdusNealimentar(){
	this->motiv = placeHolder;
}


ProdusReturnat::ProdusReturnat(const string& nume, const string& categorie, const string& motiv, int id, int cantitate, int garantieAni, float pret)
	:ProdusNealimentar(nume, categorie, id, cantitate, garantieAni, pret) {
	this->motiv = motiv;
}


void ProdusReturnat::afisare() {
	ProdusNealimentar::afisare();
	cout << "Motiv : " << this->motiv << endl;
}

string& ProdusReturnat::getMotiv() {
	return this->motiv;
}

void ProdusReturnat::setMotiv(string &motiv){
	this->motiv = motiv;
}