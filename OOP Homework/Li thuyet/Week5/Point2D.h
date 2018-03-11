#include <iostream>
using namespace std;

class Point2D {
protected:
	float x;
	float y;

public:
	Point2D(float xx = 0, float yy = 0);
	~Point2D();

	void setPoint();
	void printPoint();
};

class Circle: public Point2D {
private:
	float r;

public:
	Circle(float xx = 0, float yy = 0, float rr = 0);
	~Circle();

	void setRadius();
	void setCircle();
	void printCircle();
};