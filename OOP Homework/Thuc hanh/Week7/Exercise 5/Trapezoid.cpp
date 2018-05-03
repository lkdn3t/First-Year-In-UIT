#include "Trapezoid.h"

bool Trapezoid::isTrapezoid() {
	bool check1 = A.get_y() == B.get_y() && C.get_y() == D.get_y();
	bool check2 = A.get_y() == D.get_y() && B.get_y() == C.get_y();
	return isQuadrilateral() && (check1 || check2);
}

Trapezoid::Trapezoid(Point2D A, Point2D B, Point2D C, Point2D D) {
	this->A = A; this->B = B; this->C = C; this->D = D;
}

Trapezoid::Trapezoid(const Trapezoid & T) {
	*this = T;
}

void Trapezoid::calSurface() {
	float height, sumPar;
	if (A.get_y() == B.get_y()) {
		height = abs(A.get_y() - D.get_y());
		sumPar = A.Distance(B) + C.Distance(D);
	}
	else {
		height = abs(A.get_y() - B.get_y());
		sumPar = A.Distance(D) + B.Distance(C);
	}
	Surface = height * sumPar / 2;
}

void Trapezoid::input() {
	cout << "...Enter points of a Trapezoid...\n";
	Quadrilateral::input();

	if (!isTrapezoid()) {
		cout << " Entered points cannot found a Trapezoid\n\n";
		input();
	}
	calPerimeter();
	calSurface();
}

void Trapezoid::output() const {
	cout << "...Information of the input-Trapezoid...\n";
	Quadrilateral::output();
	cout << "\tPerimeter = " << Perimeter << endl;
	cout << "\tSurface   = " << Surface << endl;
}