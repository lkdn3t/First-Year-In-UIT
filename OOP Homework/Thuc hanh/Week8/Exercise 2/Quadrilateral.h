#pragma once
#include "Polygon.h"
class Quadrilateral : public Polygon {
public:
	Quadrilateral();
	Quadrilateral(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy);
	Quadrilateral(Point2D p1, Point2D p2, Point2D p3, Point2D p4);
	Quadrilateral(const Quadrilateral &q);
	~Quadrilateral();

public:
	float getAx() const;
	float getAy() const;
	float getBx() const;
	float getBy() const;
	float getCx() const;
	float getCy() const;
	float getDx() const;
	float getDy() const;

public:
	Point2D getPointA() const;
	Point2D getPointB() const;
	Point2D getPointC() const;
	Point2D getPointD() const;

public:
	void setAx(float Ax);
	void setAy(float Ay);
	void setBx(float Bx);
	void setBy(float By);
	void setCx(float Cx);
	void setCy(float Cy);
	void setDx(float Dx);
	void setDy(float Dy);

public:
	void setPointA(Point2D PointA);
	void setPointB(Point2D PointB);
	void setPointC(Point2D PointC);
	void setPoints(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy);
	void setPoints(Point2D p1, Point2D p2, Point2D p3, Point2D p4);

public:
	void input();
	void output() const;
};