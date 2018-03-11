#include <iostream>
#include <cmath>
using namespace std;

class Monomial {
	//Định thuộc tính của đơn thức (monomial)
	//Gồm hệ số (coefficient) và bậc - số mũ (exponent)
	int coefficient;
	int exponent;

public:
	//Định chức năng
	Monomial();
	void setMonomial();
	void setMonomial(int, int);
	void putMonomial();
	int calMonomial(int&);
	Monomial Derivative();
};

