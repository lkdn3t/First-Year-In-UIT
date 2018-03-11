#pragma once
class Polynomial {
private:
	//Định thuộc tính
	//Gồm các hệ số và bậc
	int *coefficient;
	int exponent;

public:
	Polynomial();
	void setPolynomial();
	void setPolynomial(Polynomial);
	void putPolynomial();
	void delPolynomial();

	int calPolynomial(int&);
	Polynomial getPolynomial();
	Polynomial add(Polynomial);
	Polynomial subtract(Polynomial);
};

