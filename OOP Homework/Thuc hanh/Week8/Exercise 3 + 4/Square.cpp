#include "Square.h"

bool Square::isSquare() {
	return isRectangle() && (point[0].Distance(point[1]) == point[1].Distance(point[2]));
}

Square::Square(Point2D AA, Point2D BB, Point2D CC, Point2D DD) {
	this->point[0] = AA; this->point[1] = BB; this->point[2] = CC; this->point[3] = DD;
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
}

void Square::output() const {
	cout << "...Information of the input-Square...\n";
	Quadrilateral::output();
}