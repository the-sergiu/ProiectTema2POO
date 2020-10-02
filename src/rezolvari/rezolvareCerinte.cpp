#include "rezolvareCerinte.h"

using namespace std;

RezolvareCerinte::RezolvareCerinte() {
  server = Server::InitializareServer();
}

RezolvareCerinte::~RezolvareCerinte(){
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

void RezolvareCerinte::Cerinta1(){
  cout<<"Se rezolva cerinta 1"<<endl;

  //Testare citire produse din json
  server->setMapProdusId_Produs();

  //Testare citire useri din json
  server->setMapUser_CosProduse();
}

list<Produs*> RezolvareCerinte::Cerinta2a(){
  cout<<"Se rezolva cerinta 2a"<<endl;
  list<Produs*> rezolvare;

  for (auto it = server->getListaProduse().begin(); it != server->getListaProduse().end(); ++it)
  {
    if((*it)->getProdusType() == "redus" && (*it)->getCategorie() == "espressor")
      rezolvare.push_back((*it));
  }

  return rezolvare;
}

list<User*> RezolvareCerinte::Cerinta2b(){
  cout<<"Se rezolva cerinta 2b"<<endl;
  list<User*> rezolvare;

  for (auto it = server->getListaUseri().begin(); it != server->getListaUseri().end(); ++it)
  {
    if((*it)->getUserType() == "nonpremium" && (*it)->getCostTransport() < 11.5)
      rezolvare.push_back((*it));
  }

  return rezolvare;
}

void rezolvareCerinte::Cerinta2c(){
  
  list<Produs*> rezolvare;

  for (auto it = s->getListaProduse().begin(); it != s->getListaProduse().end(); it++){
    if(((*it)->getProdusType() == "redus" || (*it)->getProdusType() == "resigilat")){
      string toFind = "cutie";
      ProdusReturnat *pr = dynamic_cast<ProdusReturnat*>(*it);

      if (pr == nullptr) continue;

      if(pr->getMotiv().find(toFind) != string::npos){
        rezolvare.push_back((*it));
      }
    }
  }

  rezolvare.sort(Utility::compareProdusNealimentar);
  
  json jrezolvare = ObjectFactory::getJsonProdus(rezolvare);
  
  cout << jrezolvare.dump(3);

  os << jrezolvare;
  rezolvare.clear();
}

void rezolvareCerinte::Cerinta2d()
{
  list<Produs*> rezolvare;

  for (auto it = s->getListaProduse().begin(); it != s->getListaProduse().end(); ++it)
  {
    if((*it)->getProdusType() == "alimentar")
      rezolvare.push_back((*it));
  }

  rezolvare.sort(Utility::compareProdusAlimentar);
  
  json jrezolvare = ObjectFactory::getJsonProdus(rezolvare);

  cout << jrezolvare.dump(3) << endl;

  cout << jrezolvare.dump(3);
  os << jrezolvare;
  rezolvare.clear();
}


list<User*> RezolvareCerinte::Cerinta2e(){
  cout<<"Se rezolva cerinta 2e"<<endl;

  list<User*> rezolvare;
  // Map de frecventa
  map<string, int> useri_per_judet;

  // Construim map-ul de frecventa, Judet:NumarUseri
  for (auto it = server->getListaUseri().begin(); it != server->getListaUseri().end(); ++it)
  {
    Adresa dateLivrare = (*it)->getDateLivrare();
    string judet = dateLivrare.getJudet();
    
    useri_per_judet[dateLivrare.getJudet()] = 0;

    if (useri_per_judet.find(judet) == useri_per_judet.end())
    {
      useri_per_judet[judet] = 0;
    }

    useri_per_judet[judet]++; 
  }
  //Afisare date din map
  //int total = 0;
  // for(auto const& x : useri_per_judet){
  // cout<<x.first<<" - "<<x.second;
  // total += x.second;
  // cout<<endl;
  // }
  // cout<<total;

  //Cautare judet cu nr maxim de useri
  auto it = useri_per_judet.begin();
  string jud_max = it->first;
  int nr_max = it->second;

  for(auto const& x : useri_per_judet){
    if (x.second > nr_max)
    {
      jud_max = x.first;
      nr_max = x.second;
    }
  }

  // Cream lista cu Utilizatori care au adresele la casa (adica nu la bloc)
  for (auto it = server->getListaUseri().begin(); it != server->getListaUseri().end(); ++it)
  {
    Adresa dateLivrare = (*it)->getDateLivrare();
    Adresa dateFacturare = (*it)->getDateFacturare();

    if(dateLivrare.getJudet() == jud_max && dateLivrare.getApartament() == 0 && dateFacturare.getApartament() == 0)
      rezolvare.push_back((*it));
  }
  // Sortare Lista
  rezolvare.sort([]( const User* const &a, const User* const &b ) { return a->getIdUser() < b->getIdUser(); });

  return rezolvare;
}

list<User*> RezolvareCerinte::Cerinta2f()
{
  cout<<"Se rezolva cerinta 2f"<<endl;

  vector<int> idsProduse;
  list<User*> rezolvare;

  // Populam lista de id-uri care corespund produselor din categoriile 'imprimanta' si 'telefon'
  for (auto it = server->getListaProduse().begin(); it != server->getListaProduse().end(); ++it)
  {
    if((*it)->getCategorie() == "telefon" || (*it)->getCategorie() == "imprimanta")
      idsProduse.push_back((*it)->getId());
  }

  // Parcugem lista de Useri, din care ne intereseaza doar Userii Premium
  for (auto it = server->getListaUseri().begin(); it != server->getListaUseri().end(); ++it)
  {
    auto userPremium = dynamic_cast<UserPremium*>((*it));
    
    if (userPremium != nullptr)
    { // Parcurgem map-ul de reduceri si verificam daca vreunul din id-uri se afla in lista idsProduse 
      // in care am retinut toate id-urile produselor reduse din acele categorii
      for (auto const& reducere : userPremium->getMapReduceri())
      {
        int idProdus = reducere.first;
        // Daca gasim un id care coincide (se afla in map si in lista idsProduse (id-urile produselor reduse))
        auto poz = find(idsProduse.begin(), idsProduse.end(), idProdus);
        
        // Bagam userul in lista finala, a carui map de reduceri corespunde cerintei de mai sus
        if (poz != idsProduse.end()) 
        { 
          rezolvare.push_back((*it));
        } 
      }
    }
  }

  return rezolvare;
}
