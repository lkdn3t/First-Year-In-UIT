#include "Rectangle.h"

bool Rectangle::isRectangle() {
	if (!isParallelogram()) return false;
	if (A.get_y() == B.get_y()) return A.get_x() == D.get_x();
	return A.get_x() == B.get_x();
}

Rectangle::Rectangle(Point2D A, Point2D B, Point2D C, Point2D D) {
	this->A = A; this->B = B; this->C = C; this->D = D;
}

Rectangle::Rectangle(const Rectangle & R) {
	*this = R;
}

void Rectangle::input() {
	cout << "...Enter points of a Rectangle...\n";
	Quadrilateral::input();

	if (!isRectangle()) {
		cout << " Entered points cannot found a Rectangle\n\n";
		input();
	}
	calPerimeter();
	calSurface();
}

void Rectangle::output() const {
	cout << "...Information of the input-Rectangle...\n";
	Quadrilateral::output();
	cout << "\tPerimeter = " << Perimeter << endl;
	cout << "\tSurface   = " << Surface << endl;
}