#include "Circle.h"

Circle::Circle(float XCenter, float YCenter, float Radius) {
	this->Center.x = XCenter;
	this->Center.y = YCenter;
	MajorAxis = MinorAxis = FocusAxis = Radius;
}

float Circle::getRadius() const {
	return MajorAxis;
}

void Circle::setRadius(float Radius) {
	MajorAxis = MinorAxis = FocusAxis = Radius;
}

void Circle::GetData() {
	cout << " Enter Center Point: ";
	cin >> Center.x >> Center.y;
	
	do {
		cout << " Enter Radius: ";
		cin >> MajorAxis;
	} while (MajorAxis <= 0);

	MinorAxis = FocusAxis = MajorAxis;
}

void Circle::PutData() const {
	cout << " Center Point: " << "C(" << Center.x << " ; " << Center.y << ")" << endl;
	cout << " Radius: " << MajorAxis << endl;
}
