#include "Trapezoid.h"

bool Trapezoid::isTrapezoid() {
	bool check1 = point[0].get_y() == point[1].get_y() && point[2].get_y() == point[3].get_y();
	bool check2 = point[0].get_y() == point[3].get_y() && point[1].get_y() == point[2].get_y();
	return isQuadrilateral() && (check1 || check2);
}

Trapezoid::Trapezoid(Point2D A, Point2D B, Point2D C, Point2D D) {
	this->point[0] = A; this->point[1] = B; this->point[2] = C; this->point[3] = D;
}

Trapezoid::Trapezoid(const Trapezoid & T) {
	*this = T;
}

void Trapezoid::input() {
	cout << "...Enter points of a Trapezoid...\n";
	Quadrilateral::input();

	if (!isTrapezoid()) {
		cout << " Entered points cannot found a Trapezoid\n\n";
		input();
	}
}

void Trapezoid::output() const {
	cout << "...Information of the input-Trapezoid...\n";
	Quadrilateral::output();
}