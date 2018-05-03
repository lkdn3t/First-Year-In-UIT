#include "Parallelogram.h"

bool Parallelogram::isParallelogram() {
	if (!isTrapezoid()) return false;
	if (A.get_y() == B.get_y()) return A.Distance(B) == C.Distance(D);
	else return A.Distance(D) == B.Distance(C);
}

Parallelogram::Parallelogram(Point2D A, Point2D B, Point2D C, Point2D D) {
	this->A = A; this->B = B; this->C = C; this->D = D;
}

Parallelogram::Parallelogram(const Parallelogram & P) {
	*this = P;
}

void Parallelogram::input() {
	cout << "...Enter points of a Parallelogram...\n";
	Quadrilateral::input();

	if (!isParallelogram()) {
		cout << " Entered points cannot found a Parallelogram\n\n";
		input();
	}
	calPerimeter();
	calSurface();
}

void Parallelogram::output() const {
	cout << "...Information of the input-Parallelogram...\n";
	Quadrilateral::output();
	cout << "\tPerimeter = " << Perimeter << endl;
	cout << "\tSurface   = " << Surface << endl;
}