#include "produsResigilat.h"

using namespace std;

ProdusResigilat::ProdusResigilat():ProdusReturnat(),ProdusRedus(), ProdusNealimentar(){
  this->procentUzura = -1;
}

ProdusResigilat::ProdusResigilat(const string& nume, const string& categorie, const string& motiv, int id, int cantitate, int garantieAni, float pret, float procentReducere, float procentUzura)
	:ProdusReturnat(nume, categorie, motiv, id, cantitate, garantieAni, pret), ProdusRedus(nume, categorie, id, cantitate, garantieAni, pret, procentReducere), ProdusNealimentar(nume, categorie, id, cantitate, garantieAni, pret){
	this->procentUzura = procentUzura;
}

void ProdusResigilat::afisare() {
	ProdusReturnat::afisare();
	cout << "Procent reducere : " << this->procentReducere << endl;
	cout << "Procent Uzura : " << this->procentUzura << endl;
}

void ProdusResigilat::setProcentUzura(int procentUzura) {
	this->procentUzura = procentUzura;
}


float ProdusResigilat::getProcentUzura() {
	return this->procentUzura;
}
