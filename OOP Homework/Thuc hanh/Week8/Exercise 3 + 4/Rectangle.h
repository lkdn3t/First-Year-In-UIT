#pragma once
#include "Parallelogram.h"

class Rectangle: public Parallelogram {
protected:
	bool isRectangle();

public:
	Rectangle() {};
	Rectangle(Point2D A, Point2D B, Point2D C, Point2D D);
	Rectangle(const Rectangle& P);

public:
	void input();
	void output() const;
};