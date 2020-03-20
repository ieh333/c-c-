#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

double const EPSILON = 0.00001;

long factoriel(int n)
{
	long result = 1;
	for(int i = 2; i<=n; i++)
	{
		result = result * i;
	}
	return result;
}

double power(double x, int n)
{
	double result = 1;
	for(int i=1; i<=n; i++)
	{
		result = result * x;
	}
	return result;
}

double chislitel(double a, int n)
{
	double result = 1.00;
	for(double i=a; i >= a-n+1; i--)
	{
		result = result * i;
	}
	return result;
}

double chlen_na_redicata(double a, double x, int n)
{
	return (chislitel(a, n) * power(x, n))/(double)factoriel(n);
}

int main()
{
	double S = 1;
	double x, a;
	int n = 1;
	cout<<"a =";
	cin>>a;
	cout<<"x =";
	cin>>x;
	double b = chlen_na_redicata(a, x, n);
	
	while(b>EPSILON)
	{
		S = S + b;
		n++;
		b = chlen_na_redicata(a, x, n);
	}
	printf("s =%.4f\n", S);
}
