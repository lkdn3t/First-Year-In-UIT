#include <iostream>

class Point2D {
private:
    float x;
    float y;

public:
    void  setX(float);
    void  setY(float);
    float getX();
    float getY();

public:
    Point2D(float xx = 0, float yy = 0);
    void inputPoint();
    void putPoint();
    void movePoint(float, float);
};