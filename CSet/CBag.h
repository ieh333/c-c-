#ifndef CBAG_H
#define CBAG_H
#include <set>

using namespace std;

class CBag
{
      private:
              multiset<int> element;
      public:
             CBag();
             ~CBag();
             multiset<int> Get();
             void Insert(int);
             void Delete(int);
             int Count();
             void Print();
             void Intersection(CBag);
             void Union(CBag);
             void Difference(CBag);
};
#endif
