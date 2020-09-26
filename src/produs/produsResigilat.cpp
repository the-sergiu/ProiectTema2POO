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

ProdusResigilat::ProdusResigilat(const ProdusResigilat& pr) : ProdusNealimentar(pr), ProdusRedus(pr), ProdusReturnat(pr)
{
	this->procentUzura = pr.procentUzura;
}

void ProdusResigilat::afisare() {
	cout << "Produs Resigilat" << endl;
	cout << "Nume Produs: " << this->nume << endl;
	cout << "Producator: " << this->producator << endl;
	cout << "Categorie: " << this->categorie << endl;
	cout << "ID: " << this->id << endl; 
	cout << "Cantitate: " << this->cantitate << endl;
	cout << "Garantie: " << this->garantieAni << " ani" << endl;
	cout << "Pret: " << this->pret << endl;
	cout << "Procent Reducere: " << this->procentReducere << endl;
	cout << "Procent Uzura: " << this->procentUzura << endl;
	cout << "Motiv retur: " << this->motiv << endl << endl;
}

void ProdusResigilat::setProcentUzura(int procentUzura) {
	this->procentUzura = procentUzura;
}


float ProdusResigilat::getProcentUzura() {
	return this->procentUzura;
}

const ProdusResigilat& ProdusResigilat::operator = (const ProdusResigilat&  a){
  this->nume = a.nume;
  this->producator = a.producator;
  this->categorie = a.categorie;
  this->id = a.id;
  this->cantitate = a.cantitate;
  this->garantieAni = a.garantieAni;
  this->pret = a.pret;
  this->procentReducere = a.procentReducere;
  this->motiv = a.motiv;
  this->procentUzura = a.procentUzura;
  
  return *this;
}

string ProdusResigilat::getProdusType(){
  return "resigilat";
}

json ProdusResigilat::toJSON(){
	return json(*this);
}
