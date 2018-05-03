#include "Point2D.h"
using namespace std;

//Định constructor và sao chép
Point2D::Point2D(float xx, float yy): x(xx), y(yy) {}

//Các hàm get - set
void  Point2D::setX(float xx)  { x = xx;   }
void  Point2D::setY(float yy)  { y = yy;   }
float Point2D::getX()          { return x; }
float Point2D::getY()          { return y; }

//Nhập một điểm
void Point2D::inputPoint() {
    cout << "   - Nhap hoanh do: "; cin >> x;
    cout << "   - Nhap tung do: " ; cin >> y;
}

//Xuất một điểm
void Point2D::putPoint() {
    cout << "(" << x << ";" << y << ")\n";
}

//Tịnh tiến một điểm
void Point2D::movePoint(float dx, float dy) { 
    x += dx;
    y += dy;
}