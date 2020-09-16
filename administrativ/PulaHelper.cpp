#include "../src/produs/produsResigilat.h"
#include "../src/produs/produsAlimentar.h"
#include <string>

using namespace std;

class PulaHelper {
  public:
    void Test1() {
      string str = "check";

      



      ProdusResigilat *pr = new ProdusResigilat(str, 25, str, str, 8.97, 3, 4, str, 70, 56);
      ProdusResigilat *pr2 = new ProdusResigilat();

    }
};