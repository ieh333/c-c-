//Zadacha 3
#include <iostream.h>
#include <conio.h>


//Functsia za razdeliane na edno tritsifreno chislo na sastavishtite go tsifri.
int sum_digits(int number)
{
   int d1, d2, d3, d;
   d1=number/100;
   d2=(number/10)%10;
   d3=number%10;
   d=d1+d2+d3;
   return d;
}


void main()
{
   clrscr();
   int dig,count;
   int d,s,n;
   count=0;
   cout<<"Vavedete edno chislo ot 1 do 27:";
   cin>>n;
   if((n>=1)&&(n<=27))
   {
      for(dig=100;dig<1000;dig++)
      {
	 s=sum_digits(dig);
	 if(n==s)
	 {
	 count++;
	 }
      }
      cout<<"Broia na tritsifrenite chisla, kadeto sumata ot tsifrite e ravna na vavedenoto chislo n e:"<<endl;
      cout<<count<<endl;
   }
   else
   {
      cout<<"Vavedenoto chislo e izvan tozi interval.";
   }
}