#include "rezolvareCerinte.h"

using namespace std;

RezolvareCerinte::RezolvareCerinte() {
  server = Server::ServerInit();
}

RezolvareCerinte::~RezolvareCerinte(){
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> RezolvareCerinte::Cerinta3a(){
  cout<<"Se rezolva cerinta 3a"<<endl;
  list<Product*> rezolvare;

  for (auto it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
  {
    if((*it)->getProductType() == "redus" && (*it)->getCategory() == "espressor")
      rezolvare.push_back((*it));
  }

  return rezolvare;
}

list<User*> RezolvareCerinte::Cerinta3b(){
  cout<<"Se rezolva cerinta 3b"<<endl;
  list<User*> rezolvare;

  for (auto it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
  {
    if((*it)->getUserType() == "nonpremium" && (*it)->getTransportCost() < 11.5)
      rezolvare.push_back((*it));
  }

  return rezolvare;
}

list<Product*> RezolvareCerinte::Cerinta3c(){
  cout<<"Se rezolva cerinta 3c"<<endl;
  list<Product*> rezolvare;

  for (auto it = server->getProductsList().begin(); it != server->getProductsList().end(); it++){
    if(((*it)->getProductType() == "redus" || (*it)->getProductType() == "resigilat")){
      string toFind = "cutie";
      ReturnedProduct *pr = dynamic_cast<ReturnedProduct*>(*it);

      if (pr == nullptr) continue;

      if(pr->getReason().find(toFind) != string::npos){
        rezolvare.push_back((*it));
      }
    }
  }

  rezolvare.sort(Utility::compareProdusNealimentar);
  
  return rezolvare;
}

list<Product*> RezolvareCerinte::Cerinta3d()
{
  cout<<"Se rezolva cerinta 3d"<<endl;
  list<Product*> rezolvare;

  for (auto it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
  {
    if((*it)->getProductType() == "alimentar")
      rezolvare.push_back((*it));
  }

  rezolvare.sort(Utility::compareProdusAlimentar);

  return rezolvare;
  
  // json jrezolvare = ObjectFactory::getJsonProdus(rezolvare);

  // cout << jrezolvare.dump(3) << endl;

  // cout << jrezolvare.dump(3);
  // os << jrezolvare;
  // rezolvare.clear();
}


list<User*> RezolvareCerinte::Cerinta3e(){
  cout<<"Se rezolva cerinta 3e"<<endl;

  list<User*> rezolvare;
  // Map de frecventa
  map<string, int> useri_per_judet;

  // Construim map-ul de frecventa, Judet:NumarUseri
  for (auto it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
  {
    Address dateLivrare = (*it)->getDeliveryData();
    string judet = dateLivrare.getCounty();
    

    if (useri_per_judet.find(judet) == useri_per_judet.end())
    {
      useri_per_judet[judet] = 0;
    }

    useri_per_judet[judet]++; 
  }
  //Afisare date din map
  // int total = 0;
  // for(auto const& x : useri_per_judet){
  // cout<<x.first<<" - "<<x.second;
  // total += x.second;
  // cout<<endl;
  // }
  // cout<<total;

  //Cautare county cu nr maxim de useri
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

  // Cream lista cu Utilizatori care au adresele la casa (adica nu la block)
  for (auto it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
  {
    Address dateLivrare = (*it)->getDeliveryData();
    Address dateFacturare = (*it)->getBillingData();

    if(dateLivrare.getCounty() == jud_max && dateLivrare.getApartment() == 0 && dateFacturare.getApartment() == 0)
      rezolvare.push_back((*it));
  }
  // Sortare Lista
  rezolvare.sort([]( const User* const &a, const User* const &b ) { return a->getUserID() < b->getUserID(); });

  return rezolvare;
}

list<User*> RezolvareCerinte::Cerinta3f()
{
  cout<<"Se rezolva cerinta 3f"<<endl;

  vector<int> idsProduse;
  list<User*> rezolvare;

  // Populam lista de id-uri care corespund produselor din categoriile 'imprimanta' si 'telefon'
  for (auto it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
  {
    if((*it)->getCategory() == "telefon" || (*it)->getCategory() == "imprimanta")
      idsProduse.push_back((*it)->getId());
  }

  // Parcugem lista de Useri, din care ne intereseaza doar Userii Premium
  for (auto it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
  {
    auto userPremium = dynamic_cast<PremiumUser*>((*it));
    
    if (userPremium != nullptr)
    { // Parcurgem map-ul de discounts si verificam daca vreunul din id-uri se afla in lista idsProduse
      // in care am retinut toate id-urile produselor reduse din acele categorii
      for (auto const& reducere : userPremium->getDiscounts())
      {
        int idProdus = reducere.first;
        // Daca gasim un id care coincide (se afla in map si in lista idsProduse (id-urile produselor reduse))
        auto poz = find(idsProduse.begin(), idsProduse.end(), idProdus);
        
        // Bagam userul in lista finala, a carui map de discounts corespunde cerintei de mai sus
        if (poz != idsProduse.end()) 
        { 
          rezolvare.push_back((*it));
        } 
      }
    }
  }

  return rezolvare;
}
