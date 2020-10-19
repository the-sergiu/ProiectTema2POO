#include "rezolvareCerinte.h"

using namespace std;

RezolvareCerinte::RezolvareCerinte()
{
	server = Server::GetInstance();
}

RezolvareCerinte::~RezolvareCerinte()
{
	if (server != nullptr)
	{
		server = nullptr;
	}
}

list<Product*> RezolvareCerinte::Cerinta3a()
{
	throw("undefined");
}

list<User *> RezolvareCerinte::Cerinta3b()
{
	throw("undefined");
}

list<Product *> RezolvareCerinte::Cerinta3c()
{
	throw("undefined");
}

list<Product *> RezolvareCerinte::Cerinta3d()
{
	throw("undefined");
}

list<User *> RezolvareCerinte::Cerinta3e()
{
	throw("undefined");
}

list<User *> RezolvareCerinte::Cerinta3f()
{
	throw("undefined");
}
