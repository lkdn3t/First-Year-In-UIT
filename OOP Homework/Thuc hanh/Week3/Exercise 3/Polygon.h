#include "Point2D.h"

class Polygon {
private:
    int NumPoint;
    Point2D *Point;
    bool isPolygon();

public:
    Polygon();
    ~Polygon();
    void getPolygon();
    void putPolygon();

public:
    void movePolygon(float, float);
    void enlargePolygon(float, Point2D);
    void shrinkPolygon(float, Point2D);
    void rotatePolygon(float, Point2D);
    void chooseBoard();
};