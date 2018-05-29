#include "Quadrilateral.h"

Quadrilateral::Quadrilateral() {
	NumberOfPoint = 4;
	point = new Point2D[4];
}

Quadrilateral::Quadrilateral(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy) {
	NumberOfPoint = 4;
	point = new Point2D[4];
	point[0].x = Ax; point[0].y = Ay;
	point[1].x = Bx; point[1].y = By;
	point[2].x = Cx; point[2].y = Cy;
	point[3].x = Dx; point[3].y = Dy;
}

Quadrilateral::Quadrilateral(Point2D p1, Point2D p2, Point2D p3, Point2D p4) {
	NumberOfPoint = 4;
	point = new Point2D[4];
	point[0] = p1; point[1] = p2; 
	point[2] = p3; point[3] = p4;
}

Quadrilateral::Quadrilateral(const Quadrilateral & t) {
	NumberOfPoint = 3;
	point = new Point2D[3];
	point[0] = t.point[0];
	point[1] = t.point[1];
	point[2] = t.point[2];
}

Quadrilateral::~Quadrilateral() {
	delete[]point;
}

float Quadrilateral::getAx() const {
	return point[0].x;
}

float Quadrilateral::getAy() const {
	return point[0].y;
}

float Quadrilateral::getBx() const {
	return point[1].x;
}

float Quadrilateral::getBy() const {
	return point[1].y;
}

float Quadrilateral::getCx() const {
	return point[2].x;
}

float Quadrilateral::getCy() const {
	return point[2].y;
}

float Quadrilateral::getDx() const {
	return point[3].x;
}

float Quadrilateral::getDy() const {
	return point[3].y;
}

Point2D Quadrilateral::getPointA() const {
	return point[0];
}

Point2D Quadrilateral::getPointB() const {
	return point[1];
}

Point2D Quadrilateral::getPointC() const {
	return point[2];
}

Point2D Quadrilateral::getPointD() const {
	return point[3];
}

void Quadrilateral::setAx(float Ax) {
	this->point[0].x = Ax;
}

void Quadrilateral::setAy(float Ay) {
	this->point[0].y = Ay;
}

void Quadrilateral::setBx(float Bx) {
	this->point[1].x = Bx;
}

void Quadrilateral::setBy(float By) {
	this->point[1].y = By;
}

void Quadrilateral::setCx(float Cx) {
	this->point[2].x = Cx;
}

void Quadrilateral::setCy(float Cy) {
	this->point[2].y = Cy;
}

void Quadrilateral::setDx(float Dx) {
	this->point[3].x = Dx;
}

void Quadrilateral::setDy(float Dy) {
	this->point[3].y = Dy;
}

void Quadrilateral::setPointA(Point2D PointA) {
	this->point[0] = PointA;
}

void Quadrilateral::setPointB(Point2D PointB) {
	this->point[1] = PointB;
}

void Quadrilateral::setPointC(Point2D PointC) {
	this->point[2] = PointC;
}

void Quadrilateral::setPoints(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy) {
	point[0].x = Ax; point[0].y = Ay;
	point[1].x = Bx; point[1].y = By;
	point[2].x = Cx; point[2].y = Cy;
	point[3].x = Dx; point[3].y = Dy;
}

void Quadrilateral::setPoints(Point2D p1, Point2D p2, Point2D p3, Point2D p4) {
	point[0] = p1;
	point[1] = p2;
	point[2] = p3;
	point[3] = p4;
}

void Quadrilateral::input() {
	cout << "...Enter Points of Quadrilateral...\n";
	Polygon::input();
}

void Quadrilateral::output() const {
	cout << "...Points of Quadrilateral...\n";
	Polygon::output();
}