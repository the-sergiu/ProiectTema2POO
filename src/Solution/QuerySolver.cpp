#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
  throw("undefined");
}

list<User*> QuerySolver::Query_3b(){
  throw("undefined");
}

list<Product*> QuerySolver::Query_3c(){
  throw("undefined");
}

list<Product*> QuerySolver::Query_3d(){
  throw("undefined");
}

list<User*> QuerySolver::Query_3e(){
  throw("undefined");
}

list<User*> QuerySolver::Query_3f()
{
  throw("undefined");
}
