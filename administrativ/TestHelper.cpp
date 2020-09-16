#include "../src/produs/produsResigilat.h"
#include "../src/produs/produsAlimentar.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../src/json.hpp"

using namespace std;
using json = nlohmann::json;

/*
  * pa <- json_in
  * pa -> json_out
  */

//  ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
//  ofs.close();

class TestHelper {
  public:
    int Test1(string inFile, string outFile) {
      string str = "check";
      // Deschidem Fisier/Afisare Mesaj/Inchidem
      ofstream oFile(outFile, ofstream::out);
      oFile << "ESUAT !";
      oFile.close();


      // Test Constructori ProdusAlimentar
      ProdusAlimentar *pa = new ProdusAlimentar();
      ProdusAlimentar *pa2 = new ProdusAlimentar(str, 78, str, 7.89, str, 200);
      
      // Test Set ProdusAlimentar
      float val = 9.27;
      string taraOrigine = "Spania";
      
      pa->setLeiPerKg(val);
      pa->setTaraDeOrigine(taraOrigine);
      
      // Test Get ProdusAlimentar
      if (pa->getLeiPerKg() != val) {
        return 1;
      }
      if (pa->getTaraDeOrigine() != taraOrigine) {
        return 1;
      }

      // OPERATORI ProdusAlimentar ???

      // Test Construcori ProdusNealimentar
      ProdusNealimentar *pn = new ProdusNealimentar();
      ProdusNealimentar *pn2 = new ProdusNealimentar(str, 20, str, str, 4.78, 30, 40);
      
      // Test Set ProdusNealimentar
      int garantie = 5;
      float pret = 5.79;
      string producator = "Adibas";
      
      pn->setGarantieAni(garantie);
      pn->setPret(pret);
      pn->setProducator(producator);
      
      // Test Get ProdusNealimentar
      if (garantie != pn->getGarantieAni()) {
          return 1;
      }
      if (pret != pn->getPret()) {
        return 1;
      }
      if (producator != pn->getProducator()) {
        return 1;
      }

      // Test Constructori ProdusRedus
      ProdusRedus *pr = new ProdusRedus();
      ProdusRedus *pr_ref = new ProdusRedus(str, 69, str, str, 4.20, 2, 60, 100);
      
      int procentReducere = 60;
      
      // Test Set ProdusRedus
      pr->setPret(pret);
      pr->setProcentReducere(procentReducere);

      // Test Get ProdusRedus
      if (pr->getPret() != pret) {
        return 1;
      }

      if (pr->getProcentReducere() != procentReducere) {
        return 1;
      }

      if (pr->pretDupaReducere() != pret * (100 - procentReducere)) {
        return 1;
      }
      
      // Test Constructori ProdusReturnat
      ProdusReturnat *prt = new ProdusReturnat();
      ProdusReturnat *prt_ref = new ProdusReturnat(str, 69, str, str, 4.20, 5, str, 51);

      string motiv = "aiurea";
      // Test Set ProdusReturnat
      prt->setMotiv(motiv);

      // Test Get ProdusReturnat
      if (prt->getMotiv() != motiv) {
        return 1;
      }
      

      // Test Constructori ProdusResigilat
      ProdusResigilat *pr_res = new ProdusResigilat();
      ProdusResigilat *pr_res2 = new ProdusResigilat(str, 5, str, str, 6.89, 25, 28, str, 29, 30);

      // Test Set ProdusResigilat
      int procent = 6;
      pr_res->setProcentUzura(procent);

      // Test Get ProdusResigilat
      if (procent != pr_res->getProcentUzura()) {
        return 1;
      }
      
      oFile.open(outFile, ofstream::out | ofstream::trunc);
      oFile << "SUCCES!";
      oFile.close();
      
      return 0;
    }
};

