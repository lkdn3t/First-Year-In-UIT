#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
protected:
	bool isSquare();

public:
	Square() {};
	Square(Point2D A, Point2D B, Point2D C, Point2D D);
	Square(const Square& P);

public:
	void input();
	void output() const;
};