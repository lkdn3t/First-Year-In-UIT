#include <iostream>

class Complex {
private:
	float real;
	float img;

public:
	Complex(float r = 0, float i = 0);
	Complex(const Complex &c);
	void setReal(float r);
	void setImg(float i);

public:
	float getReal() const;
	float getImg() const;

public:
	void input();
	void output();

public:
	Complex Add(const Complex& c) const;
	Complex Subtract(const Complex& c) const;
	Complex Multiply(const Complex& c) const;
	Complex Divide(const Complex& c) const;
};