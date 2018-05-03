#include "Point2D.h"

Point2D::Point2D(float xx, float yy) {
	x = xx; y = yy;
}

Point2D::Point2D(const Point2D & P) {
	x = P.x; y = P.y;
}

float Point2D::get_x() const {
	return x;
}

float Point2D::get_y() const {
	return y;
}

void Point2D::set_x(float x) {
	this->x = x;
}

void Point2D::set_y(float y) {
	this->y = y;
}

void Point2D::input() {
	float xx, yy;
	cin >> xx >> yy;
	x = xx; y = yy;
}

void Point2D::output() const {
	cout << "(" << x << " ; " << y << ")\n";
}

float Point2D::Distance(const Point2D& A) const {
	return sqrt((A.x - x)*(A.x - x) + (A.y - y)*(A.y - y));
}

Point2D Point2D::Vector(const Point2D& A) const {
	return Point2D(A.x - x, A.y - y);
}

bool Point2D::isEqual(const Point2D & A) const {
	return x == A.x && y == A.y;
}

bool Point2D::isInLineParallelOx(Point2D A, Point2D B) const {
	return y == A.y && y == B.y;
}

bool Point2D::isInLineParallelOy(Point2D A, Point2D B) const {
	return x == A.x && x == B.x;
}
