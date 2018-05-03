#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
	float real;
	float img;

public:
	Complex(float real = 0, float img = 0);
	void setReal(float real);
	void setImg(float img);

public:
	float getReal() const;
	float getImg() const;

public:
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

public:
	float computeModule() const;
	friend ostream& operator<<(ostream& os, const Complex& p);
	friend istream& operator>>(istream& is, Complex& p);

public:
	bool operator!=(const Complex& c) const;
	bool operator==(const Complex& c) const;
	bool operator>(const Complex& c) const;
	bool operator<(const Complex& c) const;
	bool operator>=(const Complex& c) const;
	bool operator<=(const Complex& c) const;
};