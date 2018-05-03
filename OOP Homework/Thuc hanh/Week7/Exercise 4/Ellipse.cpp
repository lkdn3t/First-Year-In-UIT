#include "Ellipse.h"

Ellipse::Ellipse(float xCenter, float yCenter, float MajorAxis, float MinorAxis, float FocusAxis) {
	this->Center.x = xCenter;
	this->Center.y = yCenter;
	this->MajorAxis = MajorAxis;
	this->MinorAxis = MinorAxis;
	this->FocusAxis = FocusAxis;
}

float Ellipse::getXCenter()   const { return Center.x;  }
float Ellipse::getYCenter()   const { return Center.y;  }
float Ellipse::getMajorAxis() const { return MajorAxis; }
float Ellipse::getMinorAxis() const { return MinorAxis; }
float Ellipse::getFocusAxis() const { return FocusAxis; }

void Ellipse::setXCenter(float XCenter)     { this->Center.x = XCenter;    }
void Ellipse::setYCenter(float YCenter)     { this->Center.y = YCenter;    }
void Ellipse::setMajorAxis(float MajorAxis) { this->MajorAxis = MajorAxis; }
void Ellipse::setMinorAxis(float MinorAxis) { this->MinorAxis = MinorAxis; }
void Ellipse::setFocusAxis(float FocusAxis) { this->FocusAxis = FocusAxis; }

void Ellipse::GetData() {
	cout << " Enter center point: ";
	cin >> Center.x >> Center.y;

	do {
		cout << " Enter Major Axis: ";
		cin >> MajorAxis;
	} while (MajorAxis <= 0);

	do {
		cout << " Enter Minor Axis: ";
		cin >> MinorAxis;
	} while (MinorAxis <= 0);
	
	do {
		cout << " Enter Focus Axis: ";
		cin >> FocusAxis;
	} while (FocusAxis <= 0 || FocusAxis >= MajorAxis);
}

void Ellipse::PutData() const {
	cout << " Center Point: C(" << Center.x << " ; " << Center.y << ")" << endl;
	cout << " Major Axis: " << MajorAxis << endl;
	cout << " Minor Axis: " << MinorAxis << endl;
	cout << " Focus Axis: " << FocusAxis << endl;
}