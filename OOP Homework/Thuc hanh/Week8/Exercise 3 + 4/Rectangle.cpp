#include "Rectangle.h"

bool Rectangle::isRectangle() {
	if (!isParallelogram()) return false;
	if (point[0].get_y() == point[1].get_y()) return point[0].get_x() == point[3].get_x();
	return point[0].get_x() == point[1].get_x();
}

Rectangle::Rectangle(Point2D AA, Point2D BB, Point2D CC, Point2D DD) {
	this->point[0] = AA; this->point[1] = BB; this->point[2] = CC; this->point[3] = DD;
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
}

void Rectangle::output() const {
	cout << "...Information of the input-Rectangle...\n";
	Quadrilateral::output();
}