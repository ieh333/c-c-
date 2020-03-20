//Zadacha 4

#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

void main()
{
	int i, k;
	double number, t;
	vector<double>A;
	vector<double>B;
	cout<<"Vavedete broia na elementite na vectora ot 1 do 50:";
	cin>>k;
		if(k>50)
		{
			cout<<"Vavedenoto chislo e izvan tozi interval.";
		}
		else
		{
			for(i=0;i<k;i++)
			{
				cout<<"Vavedete elementa na vectora:";
				cin>>number;
				A.push_back(number);
			}
		}
	for(i=0;i<k;i++)
	{
		if(A[i]>0)
		{
			t=((pow(A[i-1], 2)-2*A[i]+pow(A[i+1],2))/(A[i-1]-A[i+1]));
			B.push_back(t);
		}
		else if(A[i]<0)
		{
			t=((pow(A[i-1], 2)-2*A[i]+pow(A[i+1],2))/(A[i+1]-A[i-1]));
			B.push_back(t);
		}
		else
		{
			B.push_back(0);
		}
	}
	for(i=0;i<k;i++)
	{
		cout<<B[i]<<endl;
	}
}