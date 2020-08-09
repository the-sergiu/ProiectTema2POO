#pragma once
#include <iostream>
#include <vector>

using namespace std;

class LRUCache
{

private:
  int capacity;
  int size;
  vector<int> lru;

public:
  LRUCache(int);
  vector<int> processRequests(vector<int>);

  // get-eri
  int getCapacity();
  int getSize();
  vector<int> getLRU();

  //set-eri
  void setCapacity(int);
  void setLRU(vector<int>);

};