#include <iostream>

using namespace std;

class Fraction {
private:
	int numer;
	int denom;
	void Simplify();

public:
	Fraction(int numer = 0, int denom = 1);
	Fraction(const Fraction &f);

public:
	void setNumer(int numer);
	void setDenom(int denom);
	int  getNumer() const;
	int  getDenom() const;

public:
	Fraction operator+(const Fraction &f) const;
	Fraction operator-(const Fraction &f) const;
	Fraction operator*(const Fraction &f) const;
	Fraction operator/(const Fraction &f) const;

public:
	bool operator==(const Fraction &f) const;
	bool operator!=(const Fraction &f) const;
	bool operator>(const Fraction &f) const;
	bool operator<(const Fraction &f) const;
	bool operator>=(const Fraction &f) const;
	bool operator<=(const Fraction &f) const;

public:
	friend ostream& operator<<(ostream &os, const Fraction& f);
	friend istream& operator>>(istream &is, Fraction& f);
};