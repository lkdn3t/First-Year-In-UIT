#include "Square.h"

bool Square::isSquare() {
	return isRectangle() && (A.Distance(B) == B.Distance(C));
}

Square::Square(Point2D A, Point2D B, Point2D C, Point2D D) {
	this->A = A; this->B = B; this->C = C; this->D = D;
}

Square::Square(const Square & S) {
	*this = S;
}

void Square::input() {
	cout << "...Enter points of a Square...\n";
	Quadrilateral::input();

	if (!isSquare()) {
		cout << " Entered points cannot found a Square\n\n";
		input();
	}
	calPerimeter();
	calSurface();
}

void Square::output() const {
	cout << "...Information of the input-Square...\n";
	Quadrilateral::output();
	cout << "\tPerimeter = " << Perimeter << endl;
	cout << "\tSurface   = " << Surface << endl;
}