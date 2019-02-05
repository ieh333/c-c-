#include <iostream>
#include <set>
#include <algorithm>
#include "CBag.h"
#include "CSet.h"

using namespace std;

CSet::CSet()
{
   multiset<int> s;
}

CSet::~CSet()
{
   element2.~multiset();
}

bool CSet::isElement(int x)
{
     multiset<int>::iterator it;
     it=element2.begin();
     while(it!=element2.end())
     {
        if(x==(*it)) return true;
        it++;
     }
     return false;
}

void CSet::Insert(int x)
{
     bool isMember;
     isMember=(*this).isElement(x);
     if(isMember==false)
     {
        element2.insert(x);
     }
}

void CSet::Delete(int x)
{
     element2.erase(x);
}

int CSet::Count()
{
    int count;
    count=element2.size();
    return count;
}

void CSet::Print()
{
     multiset<int>::iterator it;
     it=element2.begin();
     while(it!=element2.end())
     {
        cout<<*it<<" ";
        it++;
     }
}

void CSet::Intersection(CSet a)
{
     CSet b;
     set_intersection(element2.begin(),element2.end(),a.element2.begin(),a.element2.end(),inserter(b.element2,b.element2.end()));
     b.Print();
}

void CSet::Union(CSet a)
{
     CSet b;
     set_union(element2.begin(),element2.end(),a.element2.begin(),a.element2.end(),inserter(b.element2,b.element2.end()));
     b.Print();
}

void CSet::Difference(CSet a)
{
     CSet b;
     set_difference(element2.begin(),element2.end(),a.element2.begin(),a.element2.end(),inserter(b.element2,b.element2.end()));
     b.Print();
}

