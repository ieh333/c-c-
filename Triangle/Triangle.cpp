#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//Daljina mejdu dve tochki
float D(int x1, int y1, int z1, int x2, int y2, int z2)
{
       float d;
       d=sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0)+pow(z2-z1,2.0));
       return d;
}

//Poluperimetar na triagalnika
float P(float a, float b, float c)
{
       float p;
       p=(a+b+c)/2;
       return p;
}

// Litse na triagalnika po Heronovata formula
float S(float a, float b, float c, float p)
{
       float s;
       s=sqrt(p*(p-a)*(p-b)*(p-c));
       return s;
}

int main()
{
    int x1,x2,x3;
    int y1,y2,y3;
    int z1,z2,z3;
    float d_a,d_b,d_c;
    float polu_p,area;
    float tg_palfa, tg_pbeta, tg_pgamma;
    cout<<"Vavedete koordinatite na tochka A:"<<endl;
    cout<<"x1=";
    cin>>x1;
    cout<<"y1=";
    cin>>y1;
    cout<<"z1=";
    cin>>z1;
    cout<<"Vavedete koordinatite na tochka B:"<<endl;
    cout<<"x2=";
    cin>>x2;
    cout<<"y2=";
    cin>>y2;
    cout<<"z2=";
    cin>>z2;
    cout<<"Vavedete koordinatite na tochka C:"<<endl;
    cout<<"x3=";
    cin>>x3;
    cout<<"y3=";
    cin>>y3;
    cout<<"z3=";
    cin>>z3;
    d_a=D(x1,y1,z1,x2,y2,z2);
    d_b=D(x2,y2,z2,x3,y3,z3);
    d_c=D(x3,y3,z3,x1,y1,z1);
    cout<<"Daljinata mejdu A i B e:"<<d_a<<endl;
    cout<<"Daljinata mejdu B i C e:"<<d_b<<endl;
    cout<<"Daljinata mejdu C i A e:"<<d_c<<endl;
    polu_p=P(d_a,d_b,d_c);
    cout<<"Poluperimetara na triagalnika e:"<<polu_p<<endl;
    area=S(d_a,d_b,d_c,polu_p);
    cout<<"Litseto na triagalnika e:"<<area<<endl;
    tg_palfa=area/(polu_p*(polu_p-d_a));
    tg_pbeta=area/(polu_p*(polu_p-d_b));
    tg_pgamma=area/(polu_p*(polu_p-d_c));
    cout<<endl;
    cout<<"tg(alfa/2)="<<tg_palfa<<endl;
    cout<<"tg(beta/2)="<<tg_pbeta<<endl;
    cout<<"tg(gamma/2)="<<tg_pgamma<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
