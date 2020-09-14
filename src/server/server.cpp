#include "server.h"

using namespace std;


void Server::setMapProdusId_Produs()
{
  for (auto it = prod.begin(); it != prod.end(); ++it)
  {
    produsId_Produs[(*it)->getId()] = *it;
  }

  //Testare initializare corecta map
  for(auto const& x : this->produsId_Produs){
  cout<<x.first<<" - ";
  x.second->afisare();
  cout<<endl;
  }
}

list<Produs*>& Server::getListaProduse()
{
  return this->prod;
}

void Server::setMapuser_CosProduse()
{
  for (auto it = usr.begin(); it != usr.end(); ++it)
  {
    user_CosProduse[(*it)->getIdUser()] = new CosProduse;
  }
  //Testare initializare corecta map
  //for(auto const& x : this->user_CosProduse){
  // cout<<x.first<<" - ";
  // x.second->afisare();
  // cout<<endl;
  //}
}

list<User*>& Server::getListaUseri()
{
  return this->usr;
}


Server::Server()
{}

Server::~Server()
{
  if (instanta != NULL)
    instanta = NULL;
  if (!produsId_Produs.empty())
    produsId_Produs.clear();
  if (!user_CosProduse.empty())
    user_CosProduse.clear();

}

Server* Server::InitializareServer()
{
  if(!instanta)
  {
    instanta = new Server;
  }
  return instanta;
}

void Server::populareProduse(const string& fisier)
{
  ifstream date(fisier);
  if (!date)
  {
    cout<<"Eroare deschidere fisier produse"<<endl;
    return;
  }

  json jin;
  date >> jin;
  prod = ObjectFactory::getProdusList(jin);
  
}

void Server::populareUseri(const string& fisier)
{
  ifstream date(fisier);
  if (!date)
  {
    cout<<"Eroare deschidere fisier useri"<<endl;
    return;
  }

  int nr_useri, id, nr_stradaf, apartamentf, nr_stradal, apartamentl, nr_reduceri, idprodus, reducere;
  float costTransport;
  unordered_map<int, int> reduceri;
  string judet, localitate, nume, prenume, email, stradaf, blocf, stradal, blocl, tip_user;

  date >> nr_useri;
  cout << "Lista de useri are " << nr_useri << " elemente" << endl;

  for (int i = 0 ; i < nr_useri; i++)
  {
    date >> tip_user;

    if (tip_user == "User_nonpremium")
    {
      date >> id;
      date >> nume;
      date >> prenume;
      date >> email;
      date >> judet;
      date >> localitate;
      date >> stradaf;
      date >> nr_stradaf;
      date >> blocf;
      date >> apartamentf;
      date >> stradal;
      date >> nr_stradal;
      date >> blocl;
      date >> apartamentl;
      date >> costTransport;
      usr.push_back(new UserNonPremium(judet, localitate, stradaf, nr_stradaf, blocf, apartamentf, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email,  costTransport));
    }

    else if (tip_user == "User_premium")
    {
      date >> id;
      date >> nume;
      date >> prenume;
      date >> email;
      date >> judet;
      date >> localitate;
      date >> stradaf;
      date >> nr_stradaf;
      date >> blocf;
      date >> apartamentf;
      date >> stradal;
      date >> nr_stradal;
      date >> blocl;
      date >> apartamentl;
      date >> nr_reduceri;

      for (int j = 0 ; j < nr_reduceri ; j++)
      {
        date >> idprodus;
        date >> reducere;
        reduceri[idprodus] = reducere;
      }

      usr.push_back(new UserPremium(judet, localitate, stradaf, nr_stradaf, blocf, apartamentf, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email,  reduceri));
      reduceri.clear(); //Curatare map
    }
  }
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



