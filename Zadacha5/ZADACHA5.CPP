//Zadacha 5
#include <iostream.h>
#include <conio.h>
#include <limits.h>
#define M 5
#define K 6


int minValue(int x, int y)
{
   if(x<y)
   {
      return x;
   }
   else if(x>y)
   {
      return y;
   }
   else
   {
      return x;
   }
}


int maxValue(int x, int y)
{
   if(x>y)
   {
      return x;
   }
   else if(x<y)
   {
      return y;
   }
   else
   {
      return x;
   }
}

void main()
{
   clrscr();
   int i,j,minimal, maximal;
   int min[M], max[K];
   minimal=INT_MAX;
   maximal=INT_MIN;
   int A[M][K];
   cout<<"Vavedete matritsta A:"<<endl;
   for(i=0;i<M;i++)
   {
      for(j=0;j<K;j++)
      {
	 cout<<"A["<<i<<"]["<<j<<"]=";
	 cin>>A[i][j];
      }
   }
   for(i=0;i<M;i++)
   {
      for(j=0;j<K;j++)
      {
	 minimal=minValue(minimal,A[i][j]);
      }
      min[i]=minimal;
      minimal=INT_MAX;
   }
   for(i=0;i<M;i++)
   {
      for(j=0;j<K;j++)
      {
	 if(A[i][j]==min[i])
	 {
	   A[i][j]=100;
	 }
      }
   }
   for(j=0;j<K;j++)
   {
      for(i=0;i<M;i++)
      {
	 maximal=maxValue(maximal,A[i][j]);
      }
      max[j]=maximal;
      maximal=INT_MIN;
   }
   cout<<endl;
   for(j=0;j<K;j++)
   {
      for(i=0;i<M;i++)
      {
	 if(A[i][j]==max[j])
	 {
	   A[i][j]=10;
	 }
      }
   }
   for(i=0;i<M;i++)
   {
      for(j=0;j<K;j++)
      {
       cout<<"A["<<i<<"]["<<j<<"]="<<A[i][j]<<endl;
      }
   }
}