#pragma once
#include "Polygon.h"

class Triangle : public Polygon {
public:
	Triangle();
	Triangle(float Ax, float Ay, float Bx, float By, float Cx, float Cy);
	Triangle(Point2D p1, Point2D p2, Point2D p3);
	Triangle(const Triangle &t);
	~Triangle();
	
public:
	float getAx() const;
	float getAy() const;
	float getBx() const;
	float getBy() const;
	float getCx() const;
	float getCy() const;
	Point2D getPointA() const;
	Point2D getPointB() const;
	Point2D getPointC() const;
	
public:
	void setAx(float Ax);
	void setAy(float Ay);
	void setBx(float Bx);
	void setBy(float By);
	void setCx(float Cx);
	void setCy(float Cy);
	void setPointA(Point2D PointA);
	void setPointB(Point2D PointB);
	void setPointC(Point2D PointC);
	void setPoints(float Ax, float Ay, float Bx, float By, float Cx, float Cy);
	void setPoints(Point2D p1, Point2D p2, Point2D p3);

public:
	void input();
	void output() const;
};