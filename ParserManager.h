#pragma once
#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "produs.h"
#include "produsAlimentar.h"
#include "produsReturnat.h"
#include "produsResigilat.h"
using json = nlohmann::json;
using namespace std;
class ParserManager
{
private:
	/*string numeField = "name";
	string cantitateField = "cantitate";
	string categorieField = "categorie";
	string leiPerKgField = "leiPerKg";
	string taraOrigineField = "taraOrigine";
	string producatorField = "producator";
	string garantieAniField = "garantieAni";
	string pretField = "pret";
	string procentReducereField = "procentReucere";
	string procentUzuraField = "procentUzura";
	string motivField = "motiv";*/

	static vector<string> produsFields;
	static vector<string> produsAlimentarFields;
	static vector<string> produsNealimentarFields;
	static vector<string> produsRedusFields;
	static vector<string> produsResigilatFields;
	static vector<string> produsReturnatFields;
protected:
	int procentUzura;
public:
	static void PutProductsInJson(vector<Produs*>&, json&);

	///TO DO 
	static void GetProductsFromJson(vector<Produs*>&, json&);

	//static void PutUsersInJson(vector<User*>&, json&);
	//static void GetUsersFromJson(vector<User*>&, json&);

private:

	//Adding Products To Json
	static void AddProdus(int, Produs*, json&);
	static void AddProdusAlimentar(int, ProdusAlimentar*, json&);
	static void AddProdusNealimentar(int, ProdusNealimentar*, json&);
	static void AddProdusRedus(int, ProdusRedus*, json&);
	static void AddProdusReturnat(int, ProdusReturnat*, json&);
	static void AddProdusResigilat(int, ProdusResigilat*, json&);
	
	//Determine what kind of product to add

	static void AddProperProductToJson(string, Produs*, json&);
	
	
};

