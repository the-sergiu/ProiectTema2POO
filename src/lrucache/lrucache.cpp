#include "lrucache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
  if (capacity <= 0)
    throw "Capacitate ar trebui sa fie mai mare ca 0!";
  this->size = 0;
  this->capacity= capacity;
  lru.resize(capacity);
}

 vector<int> LRUCache::processRequests(vector<int> requestsNo)
 {
    vector<int> ans;
    for (auto it = requestsNo.begin(); it != requestsNo.end(); ++it)
    {
      // cautam request-ul in lru
      auto it2 = find(ans.begin(), ans.end(), *it);
      // daca exista deja, doar il punem in fata
      if (it2 != ans.end())
      {
        int temp = *it2;
        ans.erase(it2);
        ans.insert(ans.begin(), temp);
      } // daca nu exista in lru, verificam size-ul
      else
      { // daca inca nu e full LRU, adaugam la inceput ID-ul
        if (size < capacity)
        {
          ans.insert(ans.begin(), *it);
          size++;
        } // daca e full, scoatem ultimul element si introducem noul elem. la inceput
        else if (size == capacity)
        {
          ans.pop_back();
          ans.insert(ans.begin(), *it);
        }
      }
    }
    setLRU(ans);
    return ans;

 }

 // get-eri
  int LRUCache::getCapacity() {
    return this->capacity;
  }
  int LRUCache::getSize() {
    return this->size;
  }
  vector<int> LRUCache::getLRU() {
    return this->lru;
  }


//set-eri
  void LRUCache::setCapacity(int capacity) {
    this->capacity = capacity;
    this->lru.resize(capacity);
  }
  void LRUCache::setLRU(vector<int> aux) {
    if (aux.size() != capacity)
      throw "Error: Mismatched size between existing LRU capcaity and setLRU parameter size";
    
   lru = aux;
  }
