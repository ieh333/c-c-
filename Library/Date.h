// Date class specification
#ifndef DATE_H
#define DATE_H
using namespace std;

class Date 
{
private:
	int d, m, y;
public:
	Date(); // Default constructor
	// Other constructor
	Date(int, int, int); 
	// set methods
	void set_day(const int& day);
	void set_month(const int& month);
	void set_year(const int& year);
	// get methods
	int get_d() const;
	int get_m() const;
	int get_y() const;
	bool valid() const; // validation date
	friend ostream& operator<<(ostream &out, const Date &date);
};
// comparison operators
bool operator == (const Date&, const Date&);
bool operator != (const Date&, const Date&);
bool operator < (const Date&, const Date&);
bool operator > (const Date&, const Date&);
bool operator <= (const Date&, const Date&);
bool operator >= (const Date&, const Date&);
#endif