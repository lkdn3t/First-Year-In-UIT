#pragma once
#include "Trapezoid.h"

class Parallelogram: public Trapezoid {
protected:
	bool isParallelogram();

public:
	Parallelogram() {};
	Parallelogram(Point2D A, Point2D B, Point2D C, Point2D D);
	Parallelogram(const Parallelogram& P);

public:
	void input();
	void output() const;
};