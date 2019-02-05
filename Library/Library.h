// Library class specification
#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX 200
#include <string>
using namespace std;

class Library
{
private:
	int count_titles;
	string title;
public:
	Library();
	void set_count_titles();
	void set_title();
	int get_count_titles() const;
	string get_title();
};

#endif