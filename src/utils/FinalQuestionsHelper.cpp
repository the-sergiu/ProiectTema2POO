#include "FinalQuestionsHelper.h"

LRU_blueprint getLruBlueprint(json &j){
    LRU_blueprint rez{
        j["capacity"].get<int>(),
        j["allLRUOperations"].get<vector<int>>()
    };
    return rez;
}

json writeLruFinalState(vector<int> &vec)
{
	json j(vec);
	return j;
}

vector<Query> getQuery(json &j){
    vector<Query> rez;
    for(json::iterator it = j.begin(); it != j.end(); it++){
        Query q{
            (*it)["productID"].get<int>(),
            (*it)["userID"].get<int>(),
            (*it)["operation"].get<string>(),
            (*it)["quantity"].get<int>()
        };
        rez.push_back(q);
    }
    return rez;
}

json queryToJson(Query &query){
    json j;
    j["productID"] = query.productID;
    j["userID"] = query.userID;
    j["operation"] = query.operation;
    j["quantity"] = query.quantity;
    return j;
}

json writeFinalState(vector<Query> &queryVec, vector<int> &lruVec)
{
	json j;
	for (vector<Query>::iterator it = queryVec.begin(); it != queryVec.end(); it++)
	{
		j.push_back(queryToJson(*it));
	}
	json jLru(lruVec);

	j.push_back(jLru);
	return j;
}
