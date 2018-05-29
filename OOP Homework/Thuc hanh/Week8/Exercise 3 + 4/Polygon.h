#pragma once
#include <iostream>
#include "Point2D.h"

using namespace std;

class Polygon {
protected:
	int NumberOfPoint;
	Point2D* point;

public:
	Polygon() {};
	Polygon(const Polygon& p);
	~Polygon();
	
public:
	void setNumberOfPoint(int NumPoint);
	Point2D* getPoints() const;
	int getNumberOfPoint() const;

public:
	virtual void input();
	virtual void output() const;
	void move(float x, float y);
};