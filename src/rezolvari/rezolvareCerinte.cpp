#include "rezolvareCerinte.h"

using namespace std;

rezolvareCerinte::rezolvareCerinte(){
  s = NULL;
  os.open("src/files/output/output.json", std::ios_base::app);
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

}