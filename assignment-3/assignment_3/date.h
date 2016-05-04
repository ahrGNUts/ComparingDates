// header file
#include <iostream>
using namespace std;

class Date;// forward declaration

// friend function prototypes
ostream &operator<< (ostream &, const Date &);
istream &operator>> (istream &, Date&);

class Date
{
private:
	int month, day, year;
public:
	Date();
	Date(const Date&); // copy constructor
	// overloaded operator prototypes
	bool operator==(const Date&);
	const Date operator=(const Date&);
	bool operator>(const Date&);
	Date operator-(const Date&);

	// friend function class prototypes for << and >>
	friend ostream &operator<< (ostream &, const Date &);
	friend istream &operator>> (istream &, Date&);

};// end Date