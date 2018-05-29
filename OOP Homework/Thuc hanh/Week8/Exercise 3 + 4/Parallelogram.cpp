#include "Parallelogram.h"

bool Parallelogram::isParallelogram() {
	if (!isTrapezoid()) return false;
	if (point[0].get_y() == point[1].get_y()) return point[0].Distance(point[1]) == point[2].Distance(point[3]);
	else return point[0].Distance(point[3]) == point[1].Distance(point[2]);
}

Parallelogram::Parallelogram(Point2D AA, Point2D BB, Point2D CC, Point2D DD) {
	this->point[0] = AA; this->point[1] = BB; this->point[2] = CC; this->point[3] = DD;
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
}

void Parallelogram::output() const {
	cout << "...Information of the input-Parallelogram...\n";
	Quadrilateral::output();
}