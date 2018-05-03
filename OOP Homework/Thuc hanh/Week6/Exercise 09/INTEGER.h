#include <iostream>

using namespace std;

class INTEGER {
private:
	int content;

public:
	INTEGER(int i = 0);
	INTEGER operator+(const INTEGER& i) const;
	INTEGER operator-(const INTEGER& i) const;
	INTEGER operator*(const INTEGER& i) const;
	INTEGER operator/(const INTEGER& i) const;
	INTEGER operator%(const INTEGER& i) const;

public:
	bool operator==(const INTEGER& i) const;
	bool operator!=(const INTEGER& i) const;
	bool operator>=(const INTEGER& i) const;
	bool operator<=(const INTEGER& i) const;
	bool operator>(const INTEGER& i) const;
	bool operator<(const INTEGER& i) const;

public:
	int GetContent();
	friend ostream& operator<<(ostream& os, const INTEGER& i);
	friend istream& operator>>(istream& is, INTEGER& i);
};