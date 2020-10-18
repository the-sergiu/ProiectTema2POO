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

void RezolvareCerinte::Cerinta2()
{
	throw("undefined");
}

list<Product *> RezolvareCerinte::Cerinta3a()
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

void RezolvareCerinte::Cerinta5()
{
	throw("undefined");
}
