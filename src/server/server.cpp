#include "server.h"

using namespace std;

// Constructori + Destructori + Init
Server::Server()
{}

Server* Server::InitializareServer()
{
  if(!instanta)
  {
    instanta = new Server;
  }
  
  return instanta;
}

Server::~Server()
{
  if (instanta != NULL)
    instanta = NULL;
  if (!produsId_Produs.empty())
    produsId_Produs.clear();
  if (!user_CosProduse.empty())
    user_CosProduse.clear();
}

// SET
void Server::setMapProdusId_Produs()
{
  for (auto it = prod.begin(); it != prod.end(); ++it)
  {
    produsId_Produs[(*it)->getId()] = *it;
  }
}



void Server::setMapUser_CosProduse()
{
  for (auto it = usr.begin(); it != usr.end(); ++it)
  {
    user_CosProduse[(*it)->getIdUser()] = new CosProduse;
  }
  //Testare initializare corecta map
  // for(auto const& x : this->user_CosProduse){
  // cout<<x.first<<" - ";
  // x.second->display();
  // cout<<endl;
  // }
}


// GET
list<Product*>& Server::getListaProduse()
{
  return this->prod;
}
list<User*>& Server::getListaUseri()
{
  return this->usr;
}

unordered_map<int, Product*> Server::getMap_Id_Produs()
{
  return this->produsId_Produs;
}

unordered_map<int, CosProduse*> Server::getMap_User_CosProdus()
{
  return this->user_CosProduse;
}


void Server::populareProduse(const json& input)
{
  prod = ObjectFactory::getProdusList(input["produse"]);
}

void Server::populareUseri(const json& input)
{
  usr = ObjectFactory::getUserList(input["useri"]);
}

// REQUESTS
void Server::requestAddProdus(int userID, int produsID, int cantitate)
{
  //Atentie verificare daca nu exista user sau produs cu id corect
  //Daca produsul cerut are cantitatea necesara
  if(produsId_Produs[produsID]->checkQuantity(cantitate)) {
  //Ii scadem cantitatea
      produsId_Produs[produsID]->decreaseQuantity(cantitate);
  //Adaugam produsul si cantitatea ceruta in cosul de produse al user-ului
    user_CosProduse[userID]->addProdus(produsID, cantitate);
  }
  //Altfel nu aveam cantitatea necesara
  else cout<<endl<<"Produsul " << produsID << " nu are cantitatea necesara"<<endl;

  //Afisare cos de produse pentru user
  cout<<"Lista de produse pentru user "<<userID<<" este: "<<endl;
  user_CosProduse[userID]->afisare();
  
}

void Server::requestDeleteProdus(int userID, int produsID)
{
  //Crestem cantitatea de produs cu cea pe care user-ul o are in cos
    produsId_Produs[produsID]->increaseQuantity(user_CosProduse[userID]->getCantitate(produsID));
  //Stergem produsul din cosul de cumparaturi
  user_CosProduse[userID]->deleteProdus(produsID);
}

void Server::requestModifyProdus(int userID, int produsID, int cantitateNoua)
{
  int diferenta = user_CosProduse[userID]->getCantitate(produsID) - cantitateNoua;

  //Daca cantitatea ceruta este mai mica decat este acum in cos
  if(diferenta > 0)
  {
    //Creste cantitatea disponibila a produslui
      produsId_Produs[produsID]->increaseQuantity(diferenta);
    //Modificam cantitatea din cos cu cea noua
    user_CosProduse[userID]->addProdus(produsID, cantitateNoua);
  }

  //Daca cantitatea ceruta este mai mare decat este acum in cos
  else if(diferenta < 0)
  {
    //Verifica daca e disponibila difereta de quantity
    if(produsId_Produs[produsID]->checkQuantity(-diferenta)) {
    //Ii scadem cantitatea
        produsId_Produs[produsID]->decreaseQuantity(-diferenta);
    //Modificam cantitatea din cos cu cea noua
      user_CosProduse[userID]->addProdus(produsID, cantitateNoua);
    }
  }

  //Altfel cantitatea este aceeasi si nu se modifica
  else cout<<endl<<"Cantitatea nu se modifica"<<endl;

}



