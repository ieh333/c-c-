// Book class specification 
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Date.h"
#include "Library.h"
using namespace std;

class Book:public Library
{
private:
	int count_authors;
	string* author_fname;
	string* author_lname;
	bool availability;
	Date date;
public:
	Book();
	void set_auth_name();
	void set_avail();
	void set_date();
	int get_count_authors() const;
	string* get_auth_name() const;
	bool get_avail() const;
	Date get_date() const;
	void print_book(ostream &out,Library &lib);
};
#endif