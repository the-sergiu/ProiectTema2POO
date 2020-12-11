#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	throw("undefined");
}

list<Product *> &Server::getProductsList()
{
	throw("undefined");
}

list<User *> &Server::getUsersList()
{
	throw("undefined");
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	throw("undefined");
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	throw("undefined");
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	throw("undefined");
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}