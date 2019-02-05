#include <iostream>
#include <set>
#include <algorithm>
#include "CBag.h"

using namespace std;

CBag::CBag()
{
     multiset<int> ms;
}

CBag::~CBag()
{
   element.~multiset();
}

multiset<int> CBag::Get()
{
   return element;
}

void CBag::Insert(int x)
{
     element.insert(x);
}

void CBag::Delete(int x)
{
     element.erase(x);
}

int CBag::Count()
{
    int count;
    count=element.size();
    return count;
}

void CBag::Print()
{
     multiset<int>::iterator it;
     it=element.begin();
     while(it!=element.end())
     {
        cout<<*it<<" ";
        it++;
     }
}

void CBag::Intersection(CBag a)
{
     CBag b;
     set_intersection(element.begin(),element.end(),a.element.begin(),a.element.end(),inserter(b.element,b.element.end()));
     b.Print();
}

void CBag::Union(CBag a)
{
     CBag b;
     set_union(element.begin(),element.end(),a.element.begin(),a.element.end(),inserter(b.element,b.element.end()));
     b.Print();
}

void CBag::Difference(CBag a)
{
     CBag b;
     set_difference(element.begin(),element.end(),a.element.begin(),a.element.end(),inserter(b.element,b.element.end()));
     b.Print();
}
