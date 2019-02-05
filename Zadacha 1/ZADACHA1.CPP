//Zadacha 1
#define MAX 10
#include <iostream.h>
#include <conio.h>

struct rectangle
{
 unsigned long a;
 unsigned long b;
 unsigned long S;
};

//Functsia za presmiatane na liste na pravoagalnik po dadeni dve strani
unsigned long calculateArea(unsigned long length,unsigned long width)
{
  unsigned long area;
   area=length*width;
   return area;
}

//Funtsia za namirane na maksimalnoto chislo mejdu dve chisla
unsigned long maxValue(unsigned long x,unsigned long y)
{
   if(x>y)
   {
      return x;
   }
   else
   {
      if(x<y)
      {
	 return y;
      }
      else
      {
	 return 0;
      }
   }
}

void main()
{
   clrscr();
   int i;
   unsigned long max,pos;
   max=0;
   pos=0;
   rectangle R[MAX];
   for(i=0;i<MAX;i++)
   {
      R[i].a=0;
      R[i].b=0;
      R[i].S=0;
   }


   for(i=0;i<MAX;i++)
   {
      cout<<"Vavedete daljinata na pravoagalnika:";
      cin>>R[i].a;
      cout<<"Vavedete shirochinata na pravoagalnika:";
      cin>>R[i].b;
      if(R[i].a!=0&&R[i].b!=0)
      {
	 R[i].S=calculateArea(R[i].a,R[i].b);
      }
      else
      {
	 break;
      }

   }
   for(i=0;i<MAX;i++)
   {
      max=maxValue(max,R[i].S);
   }
   for(i=0;i<MAX;i++)
   {
      if(max==R[i].S)
      {
	 pos=i;
	 break;
      }
   }
   cout<<endl;
   cout<<"Nai-goliamaoto litse na pravoagalnika e:"<<R[pos].S<<endl;
   cout<<"Daljinata na pravoagalnika s nai-goliamo litse e:"<<R[pos].a<<endl;
   cout<<"Shirinata na pravoagalnika s nai-goliamo litse e:"<<R[pos].b<<endl;
}      \