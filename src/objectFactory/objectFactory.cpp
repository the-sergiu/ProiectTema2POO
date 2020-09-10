#include "objectFactory.h"

///Pt serj fa si tu in pula mea asta cu definuri:: Pls :)))) :*
//Ceva de genul
#define ALIMENTAR "alimentar"
const char* produsTypes[] = {"alimentar", "nealimentar", "redus", "returnat", "resigilat"};
const char* userTypes[] = {"premium", "nonPremium"};

Produs* ObjectFactory::createProdus(string type, json::iterator it) {

    if (type == produsTypes[0]) {

        ProdusAlimentar *newProdus = new ProdusAlimentar();   
        *newProdus = it->get<ProdusAlimentar>();
        return newProdus;
    }

    if (type == produsTypes[1]) {

        ProdusNealimentar *newProdus = new ProdusNealimentar();
        *newProdus = it->get<ProdusNealimentar>();
        return newProdus;
    }

    if (type == produsTypes[2]) {

        ProdusRedus *newProdus = new ProdusRedus();
        *newProdus = it->get<ProdusRedus>();
        return newProdus;
    }

    if (type == produsTypes[3]) {

        ProdusReturnat *newProdus = new ProdusReturnat();
        *newProdus = it->get<ProdusReturnat>();
        return newProdus;
    }

    if (type == produsTypes[4]) {
            
        ProdusResigilat *newProdus = new ProdusResigilat();
        *newProdus = it->get<ProdusResigilat>();
        return newProdus;
    }
}  

vector<Produs*> ObjectFactory::getProdusVector(json j){
    
    vector<Produs*> vec;
    
    for (json::iterator it = j.begin(); it != j.end(); ++it) {

        Produs *p = createProdus((*it)[TYPE_KEY], it);
        vec.push_back(p);
    }
    return vec;

} 

json ObjectFactory::getJsonProdus(vector<Produs*>& vec){

    json outj;

    for (int i = 0; i < vec.size(); i++) {
        outj.push_back(vec[i]->toJSON());
    }

    return outj;
} 

User* ObjectFactory::createUser(string type, json::iterator it){

    if (type == userTypes[0]) {

        UserPremium *newUser = new UserPremium();   
        *newUser = it->get<UserPremium>();
        return newUser;
    }

    if (type == userTypes[1]) {

        UserNonPremium *newUser = new UserNonPremium();
        *newUser = it->get<UserNonPremium>();
        return newUser;
    }
}

vector<User*> ObjectFactory::getUsersVector(json j){

    vector<User*> vec;
    for (json::iterator it = j.begin(); it != j.end(); ++it) {

        User *p = createUser((*it)[TYPE_KEY], it);
        vec.push_back(p);
    }
    return vec;
}

json ObjectFactory::getJsonUser(vector<User*>& vec){
    json outj;

    for (int i = 0; i < vec.size(); i++) {
        outj.push_back(vec[i]->toJSON());
    }

    return outj;
}

