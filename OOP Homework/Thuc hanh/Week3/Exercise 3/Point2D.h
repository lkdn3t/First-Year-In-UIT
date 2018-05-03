#include <iostream>
#include <cmath>
#include <iomanip>

class Point2D {
private:
    float x;
    float y;

public:
    void  setX(float);
    void  setY(float);
    float getX();
    float getY();
    float diffX(Point2D);
    float diffY(Point2D);

public:
    Point2D(float xx = 0, float yy = 0);
    Point2D(const Point2D &P);
    bool isEqual(Point2D);
    void inputPoint();
    void putPoint();

public:
    void movePoint(float, float);
    void enlargePoint(float, Point2D);
    void shrinkPoint(float, Point2D);
    void rotatePoint(float, Point2D);
};