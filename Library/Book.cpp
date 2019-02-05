// Program for Books in the Library
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Library.h"
#include "Book.h"
#define MAX 200
using namespace std;

Library::Library()
{
	count_titles=0;
	title="";
}
void Library::set_count_titles()
{
	cout<<"Vavedete broia na zaglaviata na knigite v bibliotekata: ";
	cin>>count_titles;
}
void Library::set_title()
{
	cout<<"Vavedete zaglavieto na knigata: ";
	cin.ignore(1);
	getline(cin,title);
}
int Library::get_count_titles() const
{
	return count_titles;
}
string Library::get_title()
{
	return title;
}
Book::Book()
{
	Date date;
	Library lib;
	count_authors=1;
	author_fname=new string[MAX];
	author_lname=new string[MAX];
	author_fname[count_authors-1]="";
	author_lname[count_authors-1]="";
	availability=false;
	date.get_d();
	date.get_m();
	date.get_y();
}

void Book::set_auth_name()
{
	int i;
	string temp1, temp2;
	cout<<"Vavedete broia na avtorite na knigata: ";
	cin>>count_authors;
	for(i=0;i<count_authors;i++)
	   {
	   cout<<"Vavedete parvoto ime na avtora: ";
	   cin.ignore(1);
	   cin>>temp1;
	   author_fname[i]=temp1;
	   cout<<"Vavedete familiata na avtora: ";
	   cin.ignore(1);
	   cin>>temp2;
	   author_lname[i]=temp2;
	   }
}
void Book::set_avail()
{
	cout<<"Vavedete dali e nalichna knigata ili ne: "<<endl;
	cout<<"1- Knigata e nalicha."<<endl;
	cout<<"0- Knigata ne e nalicha."<<endl;
	cin>>availability;
}
void Book::set_date()
{
	int dd,mm,yy;
	bool valid;
	cout<<"Vavedete datata na zaemane na knigata: "<<endl;
	cout<<"day: ";
	cin>>dd;
	date.set_day(dd);
	cout<<"month: ";
	cin>>mm;
	date.set_month(mm);
	cout<<"year: ";
	cin>>yy;
	date.set_year(yy);
	valid=date.valid();
	if(valid==true)
	{
		cout<<"Vavedenata data e validna.\n";
	}
	else
	{
		cout<<"Vavedenata data ne e validna. Molia vavedete validna data:\n";
		set_date();
	}
}
int Book::get_count_authors() const
{
	return count_authors;
}
string* Book::get_auth_name() const
{

	string* author_name=new string[count_authors];
	*author_name=*author_fname+" "+*author_fname;
	return author_name;
}
bool Book::get_avail() const
{
	return availability;
}
Date Book::get_date() const
{
	return date;
}
void Book::print_book(ostream &out, Library& lib)
{
	int i;
	bool avail;
	avail=get_avail();
	out<<lib.get_title()<<";";
	for(i=0;i<count_authors;i++)
	{
		if(i!=count_authors-1)
		{
			out<<author_fname[i]<<" "<<author_lname[i]<<",";
		}
		else
		{
			out<<author_fname[i]<<" "<<author_lname[i]<<";";
		}
	}
	out<<avail<<";";
	if(avail==1)
	{
		out<<get_date()<<";";
	}
	else
	{
		Date date1;
		out<<date1.get_d()<<"."<<date1.get_m()<<"."<<date1.get_y()<<";";
	}
}
int main()
{
	system("cls");
	int i,count;
	bool av;
	Library lib;
	Book book;
	string file="Books.dat";
	ofstream output;
	output.open(file, ios::out);
	if(output)
	{
		lib.set_count_titles();
		count=lib.get_count_titles();
		for(i=0;i<count;i++)
		{
			lib.set_title();
			book.set_auth_name();
			book.set_avail();
			av=book.get_avail();
			if(av==1)
			{
				book.set_date();
			}
			output<<i+1<<";";
			book.print_book(output, lib);
			output<<endl;
		}
	}
	else
	{
		cerr<<"Failat ne moje da bade otvoren!";
	}
	output.close();
	return 0;
}