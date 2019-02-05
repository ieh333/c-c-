#include <iostream>
#include <set>
#include "CBag.h"
#include "CSet.h"

using namespace std;

int main()
{
    CBag a1,a2;
    CSet b1,b2;
    int e,f;
    int g,h; 
    while(cin>>e)
    {
       if(e==0) break;
       a1.Insert(e);
    }
    cout<<endl;
    while(cin>>f)
    {
       if(f==0) break;
       a2.Insert(f);
    } 
    cout<<endl;
    while(cin>>g)
    {
       if(g==0) break;
       b1.Insert(g);
    }
    cout<<endl;
    while(cin>>h)
    {
       if(h==0) break;
       b2.Insert(h);
    }
    cout<<"Intersection:"<<endl;
    a1.Intersection(a2);
    cout<<endl;
    b1.Intersection(b2);
    cout<<endl;
    cout<<"Union:"<<endl;
    a1.Union(a2);
    cout<<endl;
    b1.Union(b2);
    cout<<endl;
    cout<<"Difference:"<<endl;
    a1.Difference(a2);
    cout<<endl;
    b1.Difference(b2);
    cout<<endl;
    cout<<"Count a1:"<<a1.Count()<<endl<<"Count a2:"<<a2.Count()<<endl;
    cout<<"Count b1:"<<b1.Count()<<endl<<"Count b2:"<<b2.Count()<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
