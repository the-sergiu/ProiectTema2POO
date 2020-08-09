#include "userPremium.h"

using namespace std;


/*

unordered_map<int,int> idCosProduse;
string nume;
string prenume;
string email;
int idUser;
string dataNasterii;
Adresa dateFacturare;
Adresa dateLivrare;

*/
UserPremium::UserPremium(unordered_map<int, int> &reduceri, const string& nume, const string& prenume, const string& email, int idUser, const string& dataNasterii, const Adresa& dateFacturare, const Adresa& dateLivrare, int costAbonamentPremium)
{
  this->nume = nume;
  this->prenume = prenume;
  this->email = email;
  this->idUser = idUser;
  this->dataNasterii = dataNasterii;
  this->dateFacturare = dateFacturare;
  this->dateLivrare = dateLivrare;
  this->reduceri = reduceri;
  // Lipseste map reduceri
  this->costAbonamentPremium = costAbonamentPremium;
}

void UserPremium::vizualizareUser()
{
  cout << endl << "-----------" << "USER PREMIUM: " << this->nume << "----------" << endl;
  cout << "PROFILUL MEU:" << endl<< endl;
  cout<<"Nume: "<<this->nume<<endl;
  cout<<"Prenume: "<<this->prenume<<endl;
  cout<<"Email: "<<this->email<<endl;
  cout<<"Data Nasterii: "<<this->dataNasterii<<endl;
  cout<<"Date Facturare: "<<this->dateFacturare;
  cout<<"Date Livrare: "<<this->dateLivrare;
  cout << endl << "------------- LISTA REDUCERI -------------" << endl << endl;
  // apel functie afisare REDUCERI
  
}
