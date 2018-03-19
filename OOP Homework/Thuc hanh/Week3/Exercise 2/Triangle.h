#include "Point2D.h"

class Triangle {
private:
    Point2D A, B, C;
    bool isTriangle();

public:
    Triangle(float Ax = 0, float Ay = 0, float Bx = 0, float By = 0, float Cx = 0, float Cy = 0);
    Triangle(Point2D, Point2D, Point2D);
    void putTriangle();
    void getTriangle();

public:
    void moveTriangle(float, float);
    void enlargeTriangle(float, Point2D);
    void shrinkTriangle(float, Point2D);
    void rotateTriangle(float, Point2D);
    void chooseBoard();
};