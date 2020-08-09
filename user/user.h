#pragma once
#include <string>
#include <unordered_map>

#include "adresa.h"
#include "../produs/produsResigilat.h"
#include "../produs/produsAlimentar.h"

using namespace std;

class User
{
  protected:
    string nume;
    string prenume;
    string email;
    int idUser;
    string dataNasterii;
    Adresa dateFacturare;
    Adresa dateLivrare;
  
  public:

    // vizualizeazaProduse - la un moment de timp
    // adaugareProdus - in cos, in vector, verifici ca e in stoc
    // stergereProdus - il readauga in stoc
    // cumparaProduse - prin cos de produse
    virtual void vizualizareUser() = 0;
    
    void setNume(const string&);
    void setPrenume(const string&);
    void setEmail(const string&);
    void setIdUser(int);
    void setDataNasterii(const string&);
    
    // Trebuie sa implementam si ceilalti user, ca sa vedem daca merge Adresa
    void setDateFacturare(const Adresa&);
    void setDateLivrare(const Adresa&);

    string& getNume();
    string& getPrenume();
    string& getEmail();
    int getIdUser();
    string& getDataNasterii();
    Adresa& getDateFacturare();
    Adresa& getDateLivrare(); 
   
    virtual ~User() = 0;
};

    