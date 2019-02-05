#ifndef CSET_H
#define CSET_H
#include <set>

using namespace std;

class CSet: public CBag
{
      private:
              multiset<int> element2;
      public:
             CSet();
             ~CSet();
             bool isElement(int);
             void Insert(int);
             void Delete(int);
             int Count();
             void Print();
             void Intersection(CSet);
             void Union(CSet);
             void Difference(CSet);
};
#endif
