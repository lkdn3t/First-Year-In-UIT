#include <iostream>
using namespace std;

#pragma once
class Complex {
private:
	//Định các thuộc tính cho số phức
	//Gồm phần thực a và phần ảo b
	float a;
	float b;

public:
	//Định các phép tính và phép nhập xuất
	void inputComplex();
	void printComplex();
	Complex Add(Complex p);
	Complex Subtract(Complex p);
	Complex Multiply(Complex p);
	Complex Divide(Complex p);
};

