#include "produsNealimentar.h"

ProdusNealimentar::ProdusNealimentar() {
	this->categorie = placeHolder;
	this->id = -1;
	this->garantieAni = -1;
	this->pret = -1;
}

ProdusNealimentar::ProdusNealimentar(const string& nume, const string& categorie, int id, int cantitate, int garantieAni, float pret) {
	this->categorie = categorie;
	this->id = id;
  this->cantitate = cantitate;
	this->garantieAni = garantieAni;
	this->pret = pret;
  this->nume = nume;
}


void ProdusNealimentar::afisare(){
  cout << "Nume Produs: " << this->nume << endl;
	cout << "Categorie: " << this->categorie << endl;
	cout << "ID: " << this->id << endl; 
  cout << "Cantitate: " << this->cantitate << endl;
	cout << "Garantie: " << this->garantieAni << endl;
	cout << "Pret: " << this->pret << endl;
}

// SET-eri
void ProdusNealimentar::setNume(const string& nume)
{
  this->nume = nume;
}

void ProdusNealimentar::setCategorie(const string& categorie)
{
  this->categorie = categorie;
}

void ProdusNealimentar::setId(int id)
{
  this->id = id;
}

void ProdusNealimentar::setCantitate(int) {
  this->cantitate = cantitate;
}

void ProdusNealimentar::setGarantieAni(int garantieAni) {
	this->garantieAni = garantieAni;
}

void ProdusNealimentar::setPret(float pret) {
	this->pret = pret;
}

//GET-eri

string& ProdusNealimentar::getNume()
{
  return this->nume;
}

string& ProdusNealimentar::getCategorie()
{
  return this->categorie;
}

int ProdusNealimentar::getId()
{
  return this->id;
}

int ProdusNealimentar::getCantitate()
{
  return this->cantitate;
}

int ProdusNealimentar::getGarantieAni() {
	return this->garantieAni;
}

float ProdusNealimentar::getPret(){
	return this->pret;
}

bool ProdusNealimentar::operator == (const ProdusNealimentar& obj)const {
	return (this->pret == obj.pret) ? true : false;
}

