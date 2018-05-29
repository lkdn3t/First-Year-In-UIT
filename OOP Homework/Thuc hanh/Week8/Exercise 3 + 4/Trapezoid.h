#pragma once
#include "Quadrilateral.h"

class Trapezoid : public Quadrilateral {
protected:
	bool isTrapezoid();
	float Surface;
public:
	Trapezoid() {};
	Trapezoid(Point2D A, Point2D B, Point2D C, Point2D D);
	Trapezoid(const Trapezoid& T);

public:
	void input();
	void output() const;
};