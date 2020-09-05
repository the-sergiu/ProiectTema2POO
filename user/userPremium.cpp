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
UserPremium::UserPremium(const string& judet, const string& localitate, const string& stradaf, int nr_stradaf, const string& blocf, int apartamentf, const string& stradal, int nr_stradal, const string& blocl, int apartamentl, int id, const string& nume, const string& prenume, const string& email, const unordered_map<int, int>& reduceri) : User(judet, localitate, stradaf, nr_stradaf, blocf, apartamentf, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
  this->reduceri = reduceri;
}

void UserPremium::vizualizareUser()
{
  cout << endl << "-----------" << "USER PREMIUM: " << this->UserId << "----------" << endl;
  cout<<"Nume: "<<this->nume<<endl;
  cout<<"Prenume: "<<this->prenume<<endl;
  cout<<"Email: "<<this->email<<endl;
  cout<<"Date Facturare: "<<this->dateFacturare;
  cout<<"Date Livrare: "<<this->dateLivrare;
  cout << endl << "------------- LISTA REDUCERI -------------" << endl << endl;
  for(auto const& x : this->reduceri)
    cout << x.first << " - " << x.second << endl;
  
}
