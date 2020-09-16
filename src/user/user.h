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
    Adresa dateFacturare;
    Adresa dateLivrare;
    string nume;
    string prenume;
    string email;
    int UserId;
  
  public:
    User();
    User(const string&, const string&, const string&, int, const string&, int, const string&, const string&, const string&, int, const string&, int, int, const string&, const string&, const string&);

    void setNume(const string&);
    void setPrenume(const string&);
    void setEmail(const string&);
    void setIdUser(int);
    
    void setDateFacturare(const Adresa&);
    void setDateLivrare(const Adresa&);

    string& getNume();
    string& getPrenume();
    string& getEmail();
    int getIdUser();
    Adresa& getDateFacturare();
    Adresa& getDateLivrare(); 
   
    virtual json toJSON();
    virtual void vizualizareUser() = 0;
    virtual ~User() = 0;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, dateFacturare, dateLivrare, nume, prenume, email, UserId)
};

 