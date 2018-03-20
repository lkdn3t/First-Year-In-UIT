#include "Point2D.h"
#define pi 3.14159
using namespace std;

//Định constructor và sao chép
Point2D::Point2D(float xx, float yy): x(xx), y(yy) {}
Point2D::Point2D(const Point2D &P): x(P.x), y(P.y) {}

//Các hàm get - set
void  Point2D::setX(float xx)  { x = xx;   }
void  Point2D::setY(float yy)  { y = yy;   }
float Point2D::getX()          { return x; }
float Point2D::getY()          { return y; }

//Hàm tìm độ lệch hoành - tung độ giữa hai điểm
float Point2D::diffX(Point2D P) { return x - P.x; }
float Point2D::diffY(Point2D P) { return y - P.y; }

//Nhập một điểm
void Point2D::inputPoint() {
    cout << "   - Nhap hoanh do: "; cin >> x;
    cout << "   - Nhap tung do: " ; cin >> y;
}

//Xuất một điểm
void Point2D::putPoint() {
    cout << "(" << fixed << setprecision(2) << x << " ; " << y << ")\n";
}

//Kiểm tra hai điểm có trùng nhau không
bool Point2D::isEqual(Point2D P) {
    return (x == P.x && y == P.y);
}

//Tịnh tiến một điểm
void Point2D::movePoint(float dx, float dy) { 
    x += dx;
    y += dy;
}

//Xoay 1 điểm theo góc từ 1 điểm tâm (x0, y0) cố định
//Công thức: x' = (x - x0) * cos - (y - y0) * sin
//           y' = (x - x0) * sin + (y - y0) * cos
void Point2D::rotatePoint(float angle, Point2D P) {
    float rad = angle * pi / 180;
    float dx  = diffX(P);
    float dy  = diffY(P);
    x = dx * cos(rad) - dy * sin(rad);
    y = dx * sin(rad) + dy * cos(rad);
}

//Phóng một điểm từ tâm cho trước
void Point2D::enlargePoint(float scale, Point2D P) {
    float dx = diffX(P) * (scale - 1);
    float dy = diffY(P) * (scale - 1);
    movePoint(dx, dy);
}

//Thu một điểm từ tâm cho trước
void Point2D::shrinkPoint(float scale, Point2D P) {
    enlargePoint(1 / scale, P);
}