#pragma once
#include <iostream>

using namespace std;

struct Point2D {
	float x;
	float y;
};

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