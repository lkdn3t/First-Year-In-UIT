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
		cout << " Enter Point " << char(c + i) << ": ";
		cin >> point[i].x >> point[i].y;
	}
}

void Polygon::output() const {
	char c = 'A';
	for (int i = 0; i < NumberOfPoint; i++) {
		cout << " Point " << char(c + i) << "(" << point[i].x << " ; " << point[i].y << ")\n";
	}
}

void Polygon::move(float x, float y) {
	for (int i = 0; i < NumberOfPoint; i++)
		point[i].x += x,
		point[i].y += y;
}