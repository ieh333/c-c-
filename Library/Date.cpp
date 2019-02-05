// Defined "Date" class
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
	d=1;
	m=1;
	y=1900;
}
Date::Date(int dd, int mm, int yyyy)
{
	d=dd;
	m=mm;
	y=yyyy;
}
void Date::set_day(const int& day)
{
	d=day;
}
void Date::set_month(const int& month)
{
	m=month;
}
void Date::set_year(const int& year)
{
	y=year;
}
int Date::get_d() const
{
	return d;
}
int Date::get_m() const
{
	return m;
}
int Date::get_y() const
{
	return y;
}
bool Date::valid() const
{
	if (y<0) { return false; }
	if(m>12||m<1) { return false; }
	if(d>31||d<1) { return false; }
	if((d==31)&&(m==2||m==4||m==6||m==9||m==11)) { return false; }
	if((d==30)&&(m==2)) { return false; }
	if(y<2000) 
	{
		if((d==29&&m==2)&&((y-1900)%4!=0)) { return false; }
	}
	if(y>2000) 
	{
		if((d==29&&m==2)&&((y-2000)%4!=0)) { return false; }
	}
	return true;
}
// check for equality
bool operator == (const Date& d1, const Date& d2)
{
	if(!d1.valid()) { return false; }
	if(!d2.valid()) { return false; }
	if((d1.get_d()==d2.get_d())&&(d1.get_m()==d2.get_m())&&(d1.get_y()==d2.get_y()))
	{
		return true;
	}
	return false;
}
bool operator != (const Date& d1, const Date& d2)
{
	return !(d1==d2);
}
bool operator < (const Date& d1, const Date& d2)
{
	if(!d1.valid()) { return false; }
	if(!d2.valid()) { return false; }
	if(d1.get_y()<d2.get_y()) { return true; }
	else if(d1.get_y()>d2.get_y()) { return false; }
	else
	{
		if(d1.get_m()<d2.get_m()) { return true; }
		else if(d1.get_m()>d2.get_m()) { return false; }
		else
		{
			if(d1.get_d()<d2.get_d()) { return true; }
			else
			{
				return false;
			}
		}
	}
	return false;
}
bool operator > (const Date& d1, const Date& d2)
{
	if(d1==d2) { return false; }
	if(d1<d2) { return false; }
	return true;
}
bool operator <= (const Date& d1, const Date& d2)
{
	if(d1==d2) { return true; }
	return (d1<d2);
}
bool operator >= (const Date& d1, const Date& d2)
{
	if(d1==d2) { return true; }
	return (d1>d2);
}
inline Date previous_date(const Date& d)
{
	Date ndat;
	if(!d.valid()) { return ndat; }
	ndat=Date((d.get_d()-1),d.get_m(), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(31, (d.get_m()-1), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(30, (d.get_m()-1), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(29, (d.get_m()-1), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(28, (d.get_m()-1), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(31, 12, (d.get_y()-1));
	return ndat;
}
inline Date next_date(const Date& d)
{
	Date ndat;
	if(!d.valid()) { return ndat; }
	ndat=Date((d.get_d()+1), d.get_m(), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(1, (d.get_m()+1), d.get_y());
	if(ndat.valid()) { return ndat; }
	ndat=Date(1, 1, (d.get_y()+1));
	return ndat;
}
inline long long_date(const Date& d)
{
	if(d.valid())
	{
		return d.get_y()*10000+d.get_m()*100+d.get_d();
	}
	return -1;
}
ostream& operator<< (ostream &out, const Date &date) 
{
	out<<date.d<<"."<<date.m<<"."<<date.y;
	return out;
}
