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
	ProdusNealimentar::afisare();
  cout << "Produs Redus" << endl;
	cout << "Procent reducere : " << this->procentReducere << endl << endl;
}


float ProdusRedus::pretDupaReducere() const {
	return (100 - this->procentReducere) * this->pret;
}

float ProdusRedus::getProcentReducere() {
	return this->procentReducere;
}

void ProdusRedus::setProcentReducere(int procentReducere) {
	this->procentReducere = procentReducere;
}

json ProdusRedus::toJSON(){
	return json(*this);
}
