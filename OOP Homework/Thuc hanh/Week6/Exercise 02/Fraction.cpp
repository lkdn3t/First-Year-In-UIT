#include "Fraction.h"

using namespace std;

//Rút gọn phân số
//Tìm UCLN của tử, mẫu và chia cho UCLN
void Fraction::Simplify() {
	int gcd;
	int a = numer, b = denom;

	while (b) {
		int t = a % b;
		a = b; b = t;
	} gcd = a;

	numer /= gcd;
	denom /= gcd;

	if (denom < 0) {
		numer = -numer;
		denom = -denom;
	}
}

Fraction::Fraction(int numer, int denom) {
	this->numer = numer;
	this->denom = denom;
}

Fraction::Fraction(const Fraction & f) {
	this->numer = f.numer;
	this->denom = f.denom;
}

void Fraction::setNumer(int numer) { this->numer = numer; }
void Fraction::setDenom(int denom) { this->denom = denom; }
int  Fraction::getNumer() const    { return numer; }
int  Fraction::getDenom() const    { return denom; }

Fraction Fraction::operator+(const Fraction & f) const {
	Fraction Sum(numer * f.denom + denom * f.numer, denom * f.denom);
	Sum.Simplify();
	return Sum;
}

Fraction Fraction::operator-(const Fraction & f) const {
	Fraction Diff(numer * f.denom - denom * f.numer, denom * f.denom);
	Diff.Simplify();
	return Diff;
}

Fraction Fraction::operator*(const Fraction & f) const {
	Fraction Product(numer * f.numer, denom * f.denom);
	Product.Simplify();
	return Product;
}

Fraction Fraction::operator/(const Fraction & f) const {
	Fraction Division(numer * f.denom, denom * f.numer);
	Division.Simplify();
	return Division;
}

bool Fraction::operator==(const Fraction & f) const {
	return float(numer) / denom == float(f.numer) / f.denom;
}

bool Fraction::operator!=(const Fraction & f) const {
	return float(numer) / denom != float(f.numer) / f.denom;
}

bool Fraction::operator>(const Fraction & f) const {
	return float(numer) / denom > float(f.numer) / f.denom;
}

bool Fraction::operator<(const Fraction & f) const {
	return float(numer) / denom < float(f.numer) / f.denom;
}

bool Fraction::operator>=(const Fraction & f) const {
	return float(numer) / denom >= float(f.numer) / f.denom;
}

bool Fraction::operator<=(const Fraction & f) const{
	return float(numer) / denom <= float(f.numer) / f.denom;
}

ostream & operator<<(ostream & os, const Fraction & f) {
	os << f.numer;
	if (f.numer && f.denom != 1)
		os << "/" << f.denom;
	return os;
}

istream & operator>>(istream & is, Fraction & f) {
	do {
		is >> f.numer >> f.denom;
	} while (!f.denom);
	return is;
}