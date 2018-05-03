#include "Complex.h"

using namespace std;

float Complex::computeModule() const { 
	return sqrt(real * real + img * img); 
}

Complex::Complex(float real, float img) { 
	this->real = real; this->img  = img; 
}

void  Complex::setReal(float real) { this->real = real; }
void  Complex::setImg(float img)   { this->img = img;   }
float Complex::getReal() const     { return real;       }
float Complex::getImg() const      { return img;        }


Complex Complex::operator+(const Complex & c) const {
	return Complex(real + c.real, img + c.img);
}

Complex Complex::operator-(const Complex & c) const {
	return Complex(real - c.real, img - c.img);
}

Complex Complex::operator*(const Complex & c) const {
	return Complex(real * c.real - img * c.img, real * c.img + img * c.real);
}

Complex Complex::operator/(const Complex & c) const {
	if (!img && !c.img) return Complex(real / c.real, 0);
	float t = img * img + c.img * c.img;
	float REAL = (real * img + c.real * c.img) / t;
	float IMG  = (img * c.real - real * c.img) / t;
	return Complex(REAL, IMG);
}

bool Complex::operator!=(const Complex & c) const {
	float Module  = computeModule();
	float cModule = c.computeModule();
	return Module != cModule;
}

bool Complex::operator==(const Complex & c) const {
	float Module  = computeModule();
	float cModule = c.computeModule();
	return Module == cModule;
}

bool Complex::operator>(const Complex & c) const {
	float Module  = computeModule();
	float cModule = c.computeModule();
	return Module > cModule;
}

bool Complex::operator<(const Complex & c) const {
	float Module  = computeModule();
	float cModule = c.computeModule();
	return Module < cModule;
}

bool Complex::operator>=(const Complex & c) const {
	float Module  = computeModule();
	float cModule = c.computeModule();
	return Module >= cModule;
}

bool Complex::operator<=(const Complex & c) const {
	float Module  = computeModule();
	float cModule = c.computeModule();
	return Module <= cModule;
}

ostream & operator<<(ostream & os, const Complex & p) {
	os << p.real;
	if (p.img > 0)
		os << "+" << p.img << "i";
	else if (p.img < 0)
		os << p.img << "i";
	return os;
}

istream & operator>>(istream & is, Complex & p) {
	is >> p.real >> p.img;
	return is;
}