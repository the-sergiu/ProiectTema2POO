#include "utility.h"

bool Utility::compareProdusNealimentar(Product *p1, Product *p2)
{
	NonFoodProduct *p1_pn = dynamic_cast<NonFoodProduct *>(p1);
	NonFoodProduct *p2_pn = dynamic_cast<NonFoodProduct *>(p2);

	if (p1_pn == nullptr || p2_pn == nullptr)
		return true;

	return p1_pn->getPrice() < p2_pn->getPrice();
}

bool Utility::compareProdusAlimentar(Product *p1, Product *p2)
{

	FoodProduct *p1_pa = dynamic_cast<FoodProduct *>(p1);
	FoodProduct *p2_pa = dynamic_cast<FoodProduct *>(p2);

	if (p1_pa == nullptr || p2_pa == nullptr)
		return true;

	if (p1_pa->getName() < p2->getName())
		return true;
	if (p1_pa->getName() > p2->getName())
		return false;

	if (p1_pa->getCountryOfOrigin() < p2_pa->getCountryOfOrigin())
		return true;
	if (p1_pa->getCountryOfOrigin() > p2_pa->getCountryOfOrigin())
		return false;

	if (p1_pa->getLeiPerKg() < p2_pa->getLeiPerKg())
		return true;
	if (p1_pa->getLeiPerKg() > p2_pa->getLeiPerKg())
		return false;

	return false;
}
