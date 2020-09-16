#include "objectFactory.h"

#define ALIMENTAR   "alimentar"
#define NEALIMENTAR "nealimentar"
#define REDUS       "redus"
#define RETURNAT    "returnat"
#define RESIGILAT   "resigilat"
#define PREMIUM     "premium"
#define NONPREMIUM  "nonPremium"


Produs* ObjectFactory::createProdus(string type, json::iterator it) {

    if (type == ALIMENTAR) {

        ProdusAlimentar *newProdus = new ProdusAlimentar();   
        *newProdus = it->get<ProdusAlimentar>();
        return newProdus;
    }

    else if (type == NEALIMENTAR) {

        ProdusNealimentar *newProdus = new ProdusNealimentar();
        *newProdus = it->get<ProdusNealimentar>();
        return newProdus;
    }

    else if (type == REDUS) {

        ProdusRedus *newProdus = new ProdusRedus();
        *newProdus = it->get<ProdusRedus>();
        return newProdus;
    }

    else if (type == RETURNAT) {

        ProdusReturnat *newProdus = new ProdusReturnat();
        *newProdus = it->get<ProdusReturnat>();
        return newProdus;
    }

    else if (type == RESIGILAT) {
            
        ProdusResigilat *newProdus = new ProdusResigilat();
        *newProdus = it->get<ProdusResigilat>();
        return newProdus;
    }

    else return NULL;
}  

list<Produs*> ObjectFactory::getProdusList(json j){
    
    list<Produs*> lst;
    
    for (json::iterator it = j.begin(); it != j.end(); ++it) {

        Produs *p = createProdus((*it)[TYPE_KEY], it);
        lst.push_back(p);
    }
    return lst;

} 

json ObjectFactory::getJsonProdus(list<Produs*>& lst){

    json outj;

    for (auto it = lst.begin(); it != lst.end(); ++it){
        outj.push_back((*it)->toJSON());
    }

    return outj;
} 

User* ObjectFactory::createUser(string type, json::iterator it){

    if (type == PREMIUM) {

        UserPremium *newUser = new UserPremium();   
        *newUser = it->get<UserPremium>();
        return newUser;
    }

    else if (type == NONPREMIUM) {

        UserNonPremium *newUser = new UserNonPremium();
        *newUser = it->get<UserNonPremium>();
        return newUser;
    }

    else return NULL;
}

list<User*> ObjectFactory::getUserList(json j){

    list<User*> lst;
    for (json::iterator it = j.begin(); it != j.end(); ++it) {

        User *p = createUser((*it)[TYPE_KEY], it);
        lst.push_back(p);
    }
    return lst;
}

json ObjectFactory::getJsonUser(list<User*>& lst){
    json outj;

    for (auto it = lst.begin(); it != lst.end(); ++it){
        outj.push_back((*it)->toJSON());
    }

    return outj;
}

