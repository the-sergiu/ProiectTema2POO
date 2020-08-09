#include "produsAlimentar.h"


ProdusAlimentar::ProdusAlimentar() {
  this->nume = placeHolder;
	this->categorie = placeHolder;
  this->cantitate = 0;
	this->id = -1;
	this->leiPerKg = -1;
	this->dataExp = -1;
	this->taraOrigine = placeHolder;
}

ProdusAlimentar::ProdusAlimentar(const string &nume, const string& categorie, int id, int cantitate, float leiPerKg,  const string& dataExp, const string& taraOrigine) {
	this->nume = nume;
  this->categorie = categorie;
	this->id = id;
  this->cantitate = cantitate;
	this->leiPerKg = leiPerKg;
	this->dataExp = dataExp;
	this->taraOrigine = taraOrigine;
  
}

void ProdusAlimentar::afisare(){
  cout << "Nume produs: " << this->nume << endl;
	cout << "ID : " << this->id << endl;
	cout << "Categorie : " << this->categorie << endl;
  cout << "Cantitate (stoc): " << this->cantitate << endl; 
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Data expirare : " << this->dataExp << endl;
	cout << "Tara de Origine : " << this->taraOrigine << endl;
}
// SET-eri
void ProdusAlimentar::setCategorie(const string &categorie) {
	this->categorie = categorie;
}

void ProdusAlimentar::setCantitate(int cantitate){
  this->cantitate = cantitate;
}

void ProdusAlimentar::setId(int id) {
	this->id = id;
}

void ProdusAlimentar::setLeiPerKg(float leiPerKg) {
	this->leiPerKg = leiPerKg;
}

void ProdusAlimentar::setDataExp(const string& dataExp) {
	this->dataExp = dataExp;
}

void ProdusAlimentar::setTaraDeOrigine(const string& taraOrigine) {
	this->taraOrigine = taraOrigine;
}

void ProdusAlimentar::setNume(const string &nume)
{
  this->nume = nume;
}

// GET-eri
string& ProdusAlimentar::getCategorie(){
	return this->categorie;
}

int ProdusAlimentar::getCantitate(){
  return this->cantitate;
}

int ProdusAlimentar::getId() {
	return this->id;
}

float ProdusAlimentar::getLeiPerKg() {
	return this->leiPerKg;
}

string& ProdusAlimentar::getDataExp() {
	return this->dataExp;
}

string& ProdusAlimentar::getTaraDeOrigine() {
	return this->taraOrigine;
}

string& ProdusAlimentar::getNume() {
  return this->nume;
}

// OPERATORI
bool ProdusAlimentar::operator == (const ProdusAlimentar& obj) const {
	return (this->leiPerKg == obj.leiPerKg) ? true : false;
}

bool ProdusAlimentar::operator < (const ProdusAlimentar& obj) const {
	return (this->leiPerKg < obj.leiPerKg) ? true : false;
}

bool ProdusAlimentar::operator > (const ProdusAlimentar& obj)const{
	return (this->leiPerKg > obj.leiPerKg) ? true : false;
}

