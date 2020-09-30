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

void RezolvareCerinte::Cerinta2c(){}
void RezolvareCerinte::Cerinta2d(){}

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
  // Sortare ??
  rezolvare.sort([]( const User* const &a, const User* const &b ) { return a->getIdUser() < b->getIdUser(); });

  return rezolvare;
}

list<User*> RezolvareCerinte::Cerinta2f(){
  cout<<"Se rezolva cerinta 2f"<<endl;

  vector<int> id_uri;
  list<User*> rezolvare;

  for (auto it = server->getListaProduse().begin(); it != server->getListaProduse().end(); ++it)
  {
    if((*it)->getCategorie() == "telefon" || (*it)->getCategorie() == "imprimanta")
      id_uri.push_back((*it)->getId());
  }

  for (auto it = server->getListaUseri().begin(); it != server->getListaUseri().end(); ++it)
  {
    auto up = dynamic_cast<UserPremium*>((*it));
    if(up != nullptr)
    {
      for(auto const& x : up->getMapReduceri()){
        auto p = find(id_uri.begin(),id_uri.end(), x.first);
        if (p != id_uri.end()) 
        { 
          rezolvare.push_back((*it));
        } 
      }
    }
  }

  return rezolvare;
}