#include <iostream>
#include <cmath>

using namespace std;

class Point2D {
private:
	float x;
	float y;
	
public:
	Point2D(float xx = 0, float yy = 0);
	Point2D(const Point2D& P);
	float get_x() const;
	float get_y() const;
	void set_x(float x);
	void set_y(float y);

public:
	void input();
	void output() const;

public:
	float Distance(const Point2D& A) const;
	Point2D Vector(const Point2D& A) const;
	bool isEqual(const Point2D& A) const;
	bool isInLineParallelOx(Point2D A, Point2D B) const;
	bool isInLineParallelOy(Point2D A, Point2D B) const;
};