#include "utility.h"

bool Utility::compareProdusNealimentar(Produs *p1, Produs *p2)
{
    ProdusNealimentar *p1_pn = dynamic_cast<ProdusNealimentar*>(p1);
    ProdusNealimentar *p2_pn = dynamic_cast<ProdusNealimentar*>(p2);

    if(p1_pn == nullptr || p2_pn == nullptr) return true;

    return p1_pn->getPret() < p2_pn->getPret();
}

bool Utility::compareProdusAlimentar(Produs *p1, Produs *p2)
{

    ProdusAlimentar *p1_pa = dynamic_cast<ProdusAlimentar*>(p1);
    ProdusAlimentar *p2_pa = dynamic_cast<ProdusAlimentar*>(p2);

    if(p1_pa == nullptr || p2_pa == nullptr) return true;

    if (p1_pa->getNume() < p2->getNume()) return true;
    if (p1_pa->getNume() > p2->getNume()) return false;

    if (p1_pa->getTaraDeOrigine() < p2_pa->getTaraDeOrigine()) return true;
    if (p1_pa->getTaraDeOrigine() > p2_pa->getTaraDeOrigine()) return false;

    if (p1_pa->getLeiPerKg() < p2_pa->getLeiPerKg()) return true;
    if (p1_pa->getLeiPerKg() > p2_pa->getLeiPerKg()) return false;

    return false;
}
