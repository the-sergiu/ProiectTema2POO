#include "produsRedus.h"
using namespace std;

ProdusRedus::ProdusRedus() : ProdusNealimentar(){
	this->procentReducere = -1;
}

ProdusRedus::ProdusRedus(const string& nume, const string& categorie, int id, int garantieAni, int cantitate, float pret, float procentReducere)
	:ProdusNealimentar(nume, categorie, id, cantitate, garantieAni, pret) {
	this->procentReducere = procentReducere;
}

void ProdusRedus::afisare()  {
	ProdusNealimentar::afisare();
	cout << "Procent reducere : " << this->procentReducere << endl;
}


float ProdusRedus::pretDupaReducere() const {
	return (1 - this->procentReducere) * this->pret;
}

float ProdusRedus::getProcentReducere() {
	return this->procentReducere;
}

void ProdusRedus::setProcentReducere(int procentReducere) {
	this->procentReducere = procentReducere;
}