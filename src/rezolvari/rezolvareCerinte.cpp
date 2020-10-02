#include "rezolvareCerinte.h"

using namespace std;

rezolvareCerinte::rezolvareCerinte(){
  s = NULL;
  //os.open("src/files/output/output.json", std::ios_base::app);
  os.open("src/files/output/output.json");
}

rezolvareCerinte::~rezolvareCerinte(){
  s = NULL;
  os.close();
}

void rezolvareCerinte::Cerinta1(){
  cout<<"Se rezolva cerinta 1"<<endl;

  s = Server::InitializareServer();

  //Testare citire produse din json
  s->populareProduse("src/files/input/input_produse.json");
  s->setMapProdusId_Produs();

  //Testare citire useri din json
  s->populareUseri("src/files/input/input_useri.json");
  s->setMapUser_CosProduse();

  // json jtest1 = ObjectFactory::getJsonUser(s->getListaUseri());
  
  // ofstream os1("src/files/output/output_useri.json");
  // os1 << jtest1; 

  // json jtest2 = ObjectFactory::getJsonProdus(s->getListaProduse());
  // os << jtest2; 
}

void rezolvareCerinte::Cerinta2a(){
  cout<<"Se rezolva cerinta 2a"<<endl;
  list<Produs*> rezolvare;

  for (auto it = s->getListaProduse().begin(); it != s->getListaProduse().end(); ++it)
  {
    if((*it)->getProdusType() == "redus" && (*it)->getCategorie() == "espressor")
      rezolvare.push_back((*it));
  }

  json jrezolvare = ObjectFactory::getJsonProdus(rezolvare);
  
  os << jrezolvare; 

  rezolvare.clear();
}

void rezolvareCerinte::Cerinta2b(){
  cout<<"Se rezolva cerinta 2b"<<endl;
  list<User*> rezolvare;

    for (auto it = s->getListaUseri().begin(); it != s->getListaUseri().end(); ++it)
  {
    if((*it)->getUserType() == "nonpremium" && (*it)->getCostTransport() < 11.5)
      rezolvare.push_back((*it));
  }

  json jrezolvare = ObjectFactory::getJsonUser(rezolvare);
  
  os << jrezolvare; 

  rezolvare.clear();

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

void rezolvareCerinte::Cerinta2e(){
  cout<<"Se rezolva cerinta 2e"<<endl;

  list<User*> rezolvare;
  map<string,int> useri_per_judet;

  for (auto it = s->getListaUseri().begin(); it != s->getListaUseri().end(); ++it)
  {
    Adresa dateLivrare = (*it)->getDateLivrare();
    useri_per_judet[dateLivrare.getJudet()] = 0;
  }

  for (auto it = s->getListaUseri().begin(); it != s->getListaUseri().end(); ++it)
  {
    Adresa dateLivrare = (*it)->getDateLivrare();
    useri_per_judet[dateLivrare.getJudet()] += 1;
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

  for (auto it = s->getListaUseri().begin(); it != s->getListaUseri().end(); ++it)
  {
    Adresa dateLivrare = (*it)->getDateLivrare();
    Adresa dateFacturare = (*it)->getDateFacturare();

    if(dateLivrare.getJudet() == jud_max && dateLivrare.getApartament() == 0 && dateFacturare.getApartament() == 0)
      rezolvare.push_back((*it));
  }

  json jrezolvare = ObjectFactory::getJsonUser(rezolvare);
  os << jrezolvare; 
  rezolvare.clear();

}

void rezolvareCerinte::Cerinta2f(){
  cout<<"Se rezolva cerinta 2f"<<endl;

  vector<int> id_uri;
  list<User*> rezolvare;

  for (auto it = s->getListaProduse().begin(); it != s->getListaProduse().end(); ++it)
  {
    if((*it)->getCategorie() == "telefon" || (*it)->getCategorie() == "imprimanta")
      id_uri.push_back((*it)->getId());
  }

  for (auto it = s->getListaUseri().begin(); it != s->getListaUseri().end(); ++it)
  {
    auto up = dynamic_cast<UserPremium*>((*it));
    if(up != nullptr)
    {
      for(auto const& x : up->getMapReduceri()){
        auto p = find(id_uri.begin(),id_uri.end(),x.first);
        if (p != id_uri.end()) 
        { 
            rezolvare.push_back((*it));
        } 
      }
    }
  }

  json jrezolvare = ObjectFactory::getJsonUser(rezolvare);
  os << jrezolvare; 
  rezolvare.clear();

}


