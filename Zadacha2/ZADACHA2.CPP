// Zadacha 2
#include <iostream.h>
#include <conio.h>
#include <math.h>


//Functsia za presniatane na dadenia izras
int func(int n)
{
   int fn;
   fn=abs(((pow(n,2)+6*n+17)/111));
   return fn;
}

void main()
{
   clrscr();
   int i,y;
   i=0;
   y=func(i);
   while(y<=200)
   {
      i++;
      y=func(i);
   }
   cout<<"Parvoto estestveno chislo, koeto udovletvoriava neravenstvoto e:"<<i;
}