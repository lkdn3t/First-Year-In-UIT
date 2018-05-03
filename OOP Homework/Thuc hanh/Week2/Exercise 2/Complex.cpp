#include "Complex.h"

using namespace std;

Complex::Complex(float r, float i) {
	real = r;
	img  = i;
}

Complex::Complex(const Complex & c) {
	real = c.real;
	img  = c.img;
}

void Complex::setReal(float r) { real = r; }
void Complex::setImg(float i)  { img  = i; }

float Complex::getReal() const { return real; }
float Complex::getImg() const  { return img;  }

void Complex::input() {
	cout << " Nhap phan thuc: "; cin >> real;
	cout << " Nhap phan ao: "  ; cin >> img;
}

void Complex::output() {
	cout << real;
	if (img > 0) cout << "+" << img << "i";
	else if (img < 0) cout << img << "i";
	cout << endl;
}

Complex Complex::Add(const Complex & c) const {
	return Complex(real + c.real, img + c.img);
}

Complex Complex::Subtract(const Complex & c) const {
	return Complex(real - c.real, img - c.img);
}

Complex Complex::Multiply(const Complex & c) const {
	return Complex(real * img - c.real * c.img, real * c.img + c.real * img);
}

Complex Complex::Divide(const Complex & c) const {
	if (!img && !c.img) return Complex(real / c.real, 0);

	float t = img * img + c.img * c.img;
	float REAL = (real * img + c.real * c.img) / t;
	float IMG = (img * c.real - real * c.img) / t;
	return Complex(REAL, IMG);
}