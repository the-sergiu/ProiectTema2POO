#include "userNonPremium.h"

using namespace std;

  UserNonPremium::UserNonPremium(const string& n, const string& p, const string& e, int id, const string& data, const Adresa& df, const Adresa& dl, float cost)
  {
    nume = n;
    prenume = p;
    email = e;
    idUser = id;
    dataNasterii = data;
    dateFacturare = df;
    dateLivrare = dl;
    costTransport = cost;
  }
  
  void UserNonPremium::setCostTransport(int cost)
  {
    costTransport = cost;
  }

  int UserNonPremium::getCostTransport()
  {
    return this->costTransport;
  }

  

  void UserNonPremium::vizualizareUser()
  {
    cout << "----------" << "USER NON-PREMIUM: " << this->nume << "----------" << endl;
    cout << "PROFILUL MEU:" << endl<< endl;
    cout<<"Nume: "<<this->nume<<endl;
    cout<<"Prenume: "<<this->prenume<<endl;
    cout<<"Email: "<<this->email<<endl;
    cout<<"Data Nasterii: "<<this->dataNasterii<<endl;
    cout<<"Date Facturare: "<<this->dateFacturare;
    cout<<"Date Livrare: "<<this->dateLivrare;
    cout<<"Cost transport standard: "<<this->costTransport;

  }