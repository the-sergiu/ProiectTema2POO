#pragma once
#include <iostream>
#include <vector>

using namespace std;

class LRUCache
{

private:
	unsigned int capacity;
	unsigned int size;
	vector<int> lru;

public:
	LRUCache(int);

	/*
      * @param requestsNo vectorul ce contine id-urile ce corespund requesturilor
      * @return stadiul final al cache-ului
      */
	vector<int> processRequests(vector<int> requestsNo);

	/*
      * @return capacitatea cache-ului
      */
	int getCapacity();
	int getSize();
	/*
      * @return vectorul din spatele cache-ului
      */
	vector<int> getLRU();
	int getLRUCapacity();

	void setCapacity(int);
	void setLRU(vector<int>);
};