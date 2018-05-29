#include "Polygon.h"

Polygon::Polygon(const Polygon & p) {
	NumberOfPoint = p.NumberOfPoint;
	for (int i = 0; i < NumberOfPoint; i++)
		point[i] = p.point[i];
}

Polygon::~Polygon() {
	delete[]point;
}

void Polygon::setNumberOfPoint(int NumPoint) {
	NumberOfPoint = NumPoint;
}

Point2D * Polygon::getPoints() const {
	return point;
}

int Polygon::getNumberOfPoint() const {
	return NumberOfPoint;
}

void Polygon::input() {
	char c = 'A';
	for (int i = 0; i < NumberOfPoint; i++) {
		float xx, yy;
		cout << " Enter Point " << char(c + i) << ": ";
		cin >> xx >> yy;
		point[i].set_x(xx);
		point[i].set_y(yy);
	}
}

void Polygon::output() const {
	char c = 'A';
	for (int i = 0; i < NumberOfPoint; i++) {
		cout << " Point " << char(c + i) << "(" << point[i].get_x() << " ; " << point[i].get_y() << ")\n";
	}
}

void Polygon::move(float x, float y) {
	for (int i = 0; i < NumberOfPoint; i++)
		point[i].set_x(point[i].get_x() + x),
		point[i].set_y(point[i].get_y() + y);
}