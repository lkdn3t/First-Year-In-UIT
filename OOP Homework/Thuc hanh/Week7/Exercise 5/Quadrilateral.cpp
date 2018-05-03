#include "Quadrilateral.h"

bool Quadrilateral::isQuadrilateral() {
	bool check1 = !A.isEqual(B) && !A.isEqual(C) && !A.isEqual(D) && !B.isEqual(C) && !B.isEqual(D) && !C.isEqual(D);
	bool check2 = !A.isInLineParallelOx(B, C) && !A.isInLineParallelOx(C, D) && !B.isInLineParallelOx(C, D);
	bool check3 = !A.isInLineParallelOy(B, C) && !A.isInLineParallelOy(C, D) && !B.isInLineParallelOy(C, D);
	return check1 && check2 && check3;
}

Quadrilateral::Quadrilateral(Point2D A, Point2D B, Point2D C, Point2D D) {
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
}

Quadrilateral::Quadrilateral(const Quadrilateral & Q) {
	*this = Q;
}

Point2D Quadrilateral::getA() const {
	return A;
}

Point2D Quadrilateral::getB() const {
	return B;
}

Point2D Quadrilateral::getC() const {
	return C;
}

Point2D Quadrilateral::getD() const {
	return D;
}

void Quadrilateral::setA(Point2D A) {
	this->A = A;
}

void Quadrilateral::setB(Point2D B) {
	this->B = B;
}

void Quadrilateral::setC(Point2D C) {
	this->C = C;
}

void Quadrilateral::setD(Point2D D) {
	this->D = D;
}

void Quadrilateral::input() {
	cout << "\tEnter Point A(xA, yA): "; A.input();
	cout << "\tEnter Point B(xB, yB): "; B.input();
	cout << "\tEnter Point C(xC, yC): "; C.input();
	cout << "\tEnter Point D(xD, yD): "; D.input();
	cout << endl;
}

void Quadrilateral::output() const {
	cout << "\tPoint A"; A.output();
	cout << "\tPoint B"; B.output();
	cout << "\tPoint C"; C.output();
	cout << "\tPoint D"; D.output();
}

void Quadrilateral::calPerimeter() {
	Perimeter = A.Distance(B) + B.Distance(C) + C.Distance(D) + D.Distance(A);
}