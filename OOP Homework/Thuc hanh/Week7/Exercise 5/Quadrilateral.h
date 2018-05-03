#include "Point2D.h"

class Quadrilateral {
protected:
	Point2D A, B, C, D;
	bool isQuadrilateral();
	float Perimeter;

public:
	Quadrilateral() {};
	Quadrilateral(Point2D A, Point2D B, Point2D C, Point2D D);
	Quadrilateral(const Quadrilateral& Q);

public:
	Point2D getA() const;
	Point2D getB() const;
	Point2D getC() const;
	Point2D getD() const;

public:
	void setA(Point2D A);
	void setB(Point2D B);
	void setC(Point2D C);
	void setD(Point2D D);
	
public:
	virtual void input();
	virtual void output() const;
	void calPerimeter();
};