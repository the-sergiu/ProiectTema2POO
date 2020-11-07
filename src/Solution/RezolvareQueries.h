#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../utils/utility.h"
#include "Product/ResealedProduct.h"
#include "Product/FoodProduct.h"
#include "Server/Server.h"
#include "User/PremiumUser.h"
#include "User/BasicUser.h"
#include "LRUCache/LRUCache.h"
#include "../utils/objectFactory/objectFactory.h"

/*
 * Clasa ce contine metodele in care vor fi scrise rezolvarile
 * aferente cerintelor cu query-uri (Cerinta 3)
 */
class RezolvareQueries
{
private:
	Server *server;
	LRUCache *lru;

public:
	RezolvareQueries();
	~RezolvareQueries();
	list<Product *> Cerinta3a();
	list<User *> Cerinta3b();
	list<Product *> Cerinta3c();
	list<Product *> Cerinta3d();
	list<User *> Cerinta3e();
	list<User *> Cerinta3f();
};