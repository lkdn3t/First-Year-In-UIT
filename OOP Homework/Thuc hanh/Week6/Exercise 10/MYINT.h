#include <iostream>

using namespace std;

class MYINT {
private:
	int content;

public:
	MYINT(int i = 0);
	MYINT operator+(const MYINT& i) const;
	MYINT operator-(const MYINT& i) const;
	MYINT operator*(const MYINT& i) const;
	MYINT operator/(const MYINT& i) const;
	MYINT operator%(const MYINT& i) const;

public:
	bool operator==(const MYINT& i) const;
	bool operator!=(const MYINT& i) const;
	bool operator>=(const MYINT& i) const;
	bool operator<=(const MYINT& i) const;
	bool operator>(const MYINT& i) const;
	bool operator<(const MYINT& i) const;

public:
	int GetContent();
	friend ostream& operator<<(ostream& os, const MYINT& i);
	friend istream& operator>>(istream& is, MYINT& i);
};