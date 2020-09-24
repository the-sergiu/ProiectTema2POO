#include "produsResigilat.h"

using namespace std;

ProdusResigilat::ProdusResigilat() {
  this->procentUzura = -1;
}

ProdusResigilat::ProdusResigilat(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, int procentReducere, const string& motiv, int procentUzura, int cantitate)
	:	ProdusNealimentar(categorie, id, producator, nume, pret, garantieAni, cantitate) {
		ProdusRedus(categorie, id, producator, nume, pret, garantieAni, procentReducere, cantitate),
	 	ProdusReturnat(categorie, id, producator, nume, pret, garantieAni, motiv, cantitate), 
	this->procentUzura = procentUzura;
}

void ProdusResigilat::afisare() {
	ProdusReturnat::afisare();
  	cout << "Produs Resigilat" << endl;
	cout << "Procent Reducere : " << this->procentReducere << endl;
	cout << "Procent Uzura : " << this->procentUzura << endl << endl;
}

void ProdusResigilat::setProcentUzura(int procentUzura) {
	this->procentUzura = procentUzura;
}


float ProdusResigilat::getProcentUzura() {
	return this->procentUzura;
}

json ProdusResigilat::toJSON(){
	return json(*this);
}
