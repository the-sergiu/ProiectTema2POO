#include "ParserManager.h"

vector<string> ParserManager::produsFields = { "nume", "cantitate", "categorie" };
vector<string> ParserManager::produsAlimentarFields = { "leiPerKg", "taraOrigine" };
vector<string> ParserManager::produsNealimentarFields = { "producator", "gatantieAni", "pret" };
vector<string> ParserManager::produsRedusFields = { "procentReducere" };
vector<string> ParserManager::produsResigilatFields = { "procentUzura" };
vector<string> ParserManager::produsReturnatFields = { "motiv" };

void ParserManager::PutProductsInJson(vector<Produs*>& products, json& j) {

	int size = products.size();

	for (int i = 0; i < size; i++) {
		AddProperProductToJson(to_string(products[i]->getId()), products[i], j);
	}
}


void ParserManager::AddProdus(int id, Produs* produs, json& j) {
	
	int size = produsFields.size();
	j[to_string(id)][produsFields[0]] = produs->getNume();
	j[to_string(id)][produsFields[1]] = produs->getCantitate();
	j[to_string(id)][produsFields[2]] = produs->getCategorie();

}

void ParserManager::AddProdusAlimentar(int id, ProdusAlimentar* produs, json& j) {
	
	AddProdus(id, produs, j);
	j[to_string(id)][produsAlimentarFields[0]] = produs->getLeiPerKg();
	j[to_string(id)][produsAlimentarFields[1]] = produs->getTaraDeOrigine();

}

void ParserManager::AddProdusNealimentar(int id, ProdusNealimentar* produs, json& j) {
	AddProdus(id, produs, j);
	j[to_string(id)][produsNealimentarFields[0]] = produs->getProducator();
	j[to_string(id)][produsNealimentarFields[1]] = produs->getGarantieAni();
	j[to_string(id)][produsNealimentarFields[2]] = produs->getPret();
}

void ParserManager::AddProdusRedus(int id, ProdusRedus* produs, json& j) {

	AddProdusNealimentar(id, produs, j);
	j[to_string(id)][produsRedusFields[0]] = produs->getProcentReducere();

}

void ParserManager::AddProdusReturnat(int id, ProdusReturnat* produs, json& j) {

	AddProdusNealimentar(id, produs, j);
	j[to_string(id)][produsReturnatFields[0]] = produs->getMotiv();
}

void ParserManager::AddProdusResigilat(int id, ProdusResigilat* produs, json& j) {

	AddProdusRedus(id, produs, j);
	j[to_string(id)][produsReturnatFields[0]] = produs->getMotiv();
	j[to_string(id)][produsResigilatFields[0]] = produs->getProcentUzura();

}



///Partea asta cu stabilirea obiectului potrivit trebuie modificata
/// Trebuie umblat la modul in care sunt compuse indexurile
void ParserManager::AddProperProductToJson(string idStr, Produs* product, json& j) {

	if (idStr[0] == '1')
	{
		ProdusAlimentar* pa = dynamic_cast<ProdusAlimentar*>(product);
		AddProdusAlimentar(stoi(idStr), pa, j);
	}
	else if (idStr[0] == '2')
	{
		ProdusNealimentar *pn = dynamic_cast<ProdusNealimentar*>(product);
		AddProdusNealimentar(stoi(idStr), pn, j);
	}
	else if (idStr[0] == '3') 
	{
		ProdusRedus* pr = dynamic_cast<ProdusRedus*>(product);
		AddProdusRedus(stoi(idStr), pr, j);
	}
	else if (idStr[0] == '4') 
	{
		ProdusReturnat* ret = dynamic_cast<ProdusReturnat*>(product);
		AddProdusReturnat(stoi(idStr), ret, j);
	}
	else if (idStr[0] == '5') 
	{
		ProdusResigilat* res = dynamic_cast<ProdusResigilat*>(product);
		AddProdusResigilat(stoi(idStr), res, j);
	}
}

