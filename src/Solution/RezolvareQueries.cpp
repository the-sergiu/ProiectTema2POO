#include "RezolvareQueries.h"

using namespace std;

RezolvareQueries::RezolvareQueries()
{
	server = Server::GetInstance();
}

RezolvareQueries::~RezolvareQueries()
{
	if (server != nullptr)
	{
		server = nullptr;
	}
}

list<Product *> RezolvareQueries::Cerinta3a()
{
	throw("undefined");
}

list<User *> RezolvareQueries::Cerinta3b()
{
	throw("undefined");
}

list<Product *> RezolvareQueries::Cerinta3c()
{
	throw("undefined");
}

list<Product *> RezolvareQueries::Cerinta3d()
{
	throw("undefined");
}

list<User *> RezolvareQueries::Cerinta3e()
{
	throw("undefined");
}

list<User *> RezolvareQueries::Cerinta3f()
{
	throw("undefined");
}
