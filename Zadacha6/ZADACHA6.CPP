//Zadacha 6
#include <iostream.h>
#include <conio.h>
#define N 50

struct imot
{
   char vid[20];
   char raion[10];
   int plosht;
   float tsena;
   char telephon[10];
   char address[30];
};


void main()
{
   clrscr();
   int i,count;
   imot T[N];
   cout<<"Vavedete imota:"<<endl;
   for(i=0;i<N;i++)
   {
    cout<<"Vid:";
    cin>>T[i].vid;
    cout<<"Raion:";
    cin>>T[i].raion;
    cout<<"Plosht:";
    cin>>T[i].plosht;
    cout<<"Tsena:";
    cin>>T[i].tsena;
    cout<<"Telephone:";
    cin>>T[i].telephon;
    cout<<"Address:";
    cin>>T[i].address;
   }
   for(i=0;i<N;i++)
   {
      if((T[i].address=="kv. Levski")&&(T[i].tsena<50000))
      {
	 for(count=0;count<20;count++)
	 {
	    cout<<T[i].vid<<endl;
	 }
	 for(count=0;count<10;count++)
	 {
	    cout<<T[i].raion<<endl;
	 }
	 cout<<T[i].plosht<<endl;
	 cout<<T[i].tsena<<endl;
	 for(count=0;count<10;count++)
	 {
	    cout<<T[i].telephon<<endl;
	 }
	 for(count=0;count<30;count++)
	 {
	    cout<<T[i].address<<endl;
	 }
      }
   }


}