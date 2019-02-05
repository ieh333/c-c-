#include<iostream.h>

class TstA
{
   static int c;
   double d;
   int n;
   public:
      TstA(int x=1):d(x*2.)
      {
	 n=c--;
      }
      TstA(TstA &t)
      {
	 d=t.d;
	 n=t.n*10-c--;
      }
      ~TstA()
      {
	 cout<<"End#"<<n<<endl;
	 c++;
      }
      void show()
      {
	 cout<<"Tst#"<<n<<": "<<d<<endl;
      }
      static int status()
      {
	 return c;
      }
};

int TstA::c=0;
void f(TstA t)
{
   t.show();
}

void main()
{
   TstA b[2];
   {
      TstA a(5), c=a;
      cout<<c.status()<<endl;
      for(int i=0;i<2;i++) b[i].show();
      f(c);
   }
   cout<<TstA::status()<<endl;
}
