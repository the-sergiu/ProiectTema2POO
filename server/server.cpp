#include "server.h"

using namespace std;

// eventual parametru fisier
// trebuie modificat in map
void Server::setListaProduse()
{
  string str="test";
  prod.push_back(new ProdusAlimentar(str, str, 2, 110, 5.55, str, str));
  prod.push_back(new ProdusNealimentar(str, str, 210, 5, 2, 2131.32143));
  prod.push_back(new ProdusRedus(str, str, 432, 5, 10, 4324234234, 10));
  prod.push_back(new ProdusReturnat(str, str, str, 435, 5, 2, 432423));
  prod.push_back(new ProdusResigilat(str, str, str, 789, 3, 5, 4234, 10, 22.5));

  //Set map ProdusID - Produs
  auto it = prod.begin();
  produsId_Produs[2] = *it;
  advance(it,1);
  produsId_Produs[210] = *it;
  advance(it,1);
  produsId_Produs[432] = *it;
  advance(it,1);
  produsId_Produs[435] = *it;
  advance(it,1);
  produsId_Produs[789] = *it;
}

list<Produs*>& Server::getListaProduse()
{
  return this->prod;
}

void Server::setListaUseri()
{
  string str = "test";
  Adresa adr(str, 2, str, 9);
  unordered_map<int, int> reduceri;
  reduceri[0] = 5;
  
  usr.push_back(new UserPremium(reduceri, str, str, str, 251, str, adr, adr, 69));
  usr.push_back(new UserNonPremium(str, str, str, 101, str, adr, adr, 15));

   //Set map User - cosProduse
  user_CosProduse[251] = new CosProduse;
  user_CosProduse[101] = new CosProduse;
}

list<User*>& Server::getListaUseri()
{
  return this->usr;
}


Server::Server()
{
  //TESTARE SET LISTE USERI SI PRODUSE. FINAL VA FI DIN FISIERE
 setListaProduse();
 setListaUseri();

}

Server* Server::InitializareServer()
{
  if(!instanta)
  {
    instanta = new Server;
  }
  return instanta;
}

void Server::requestAddProdus(int userID, int produsID, int cantitate)
{
  //Atentie verificare daca nu exista user sau produs cu id corect
  //Daca produsul cerut are cantitatea necesara
  if(produsId_Produs[produsID]->checkCantitate(cantitate)) {
  //Ii scadem cantitatea
    produsId_Produs[produsID]->scadeCantitate(cantitate);
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
  produsId_Produs[produsID]->cresteCantitate(user_CosProduse[userID]->getCantitate(produsID));
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
    produsId_Produs[produsID]->cresteCantitate(diferenta);
    //Modificam cantitatea din cos cu cea noua
    user_CosProduse[userID]->addProdus(produsID, cantitateNoua);
  }

  //Daca cantitatea ceruta este mai mare decat este acum in cos
  else if(diferenta < 0)
  {
    //Verifica daca e disponibila difereta de cantitate 
    if(produsId_Produs[produsID]->checkCantitate(-diferenta)) {
    //Ii scadem cantitatea
      produsId_Produs[produsID]->scadeCantitate(-diferenta);
    //Modificam cantitatea din cos cu cea noua
      user_CosProduse[userID]->addProdus(produsID, cantitateNoua);
    }
  }

  //Altfel cantitatea este aceeasi si nu se modifica
  else cout<<endl<<"Cantitatea nu se modifica"<<endl;

}



