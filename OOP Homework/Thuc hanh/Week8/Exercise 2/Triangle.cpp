#include "Triangle.h"

Triangle::Triangle() {
	NumberOfPoint = 3;
	point = new Point2D[3];
}

Triangle::Triangle(float Ax, float Ay, float Bx, float By, float Cx, float Cy) {
	NumberOfPoint = 3;
	point = new Point2D[3];
	point[0].x = Ax; point[0].y = Ay;
	point[1].x = Bx; point[1].y = By;
	point[2].x = Cx; point[2].y = Cy;
}

Triangle::Triangle(Point2D p1, Point2D p2, Point2D p3) {
	NumberOfPoint = 3;
	point = new Point2D[3];
	point[0] = p1; point[1] = p2; point[2] = p3;
}

Triangle::Triangle(const Triangle & t) {
	NumberOfPoint = 3;
	point = new Point2D[3];
	point[0] = t.point[0];
	point[1] = t.point[1];
	point[2] = t.point[2];
}

Triangle::~Triangle() {
	delete[]point;
}

float Triangle::getAx() const {
	return point[0].x;
}

float Triangle::getAy() const {
	return point[0].y;
}

float Triangle::getBx() const {
	return point[1].x;
}

float Triangle::getBy() const {
	return point[1].y;
}

float Triangle::getCx() const {
	return point[2].x;
}

float Triangle::getCy() const {
	return point[2].y;
}

Point2D Triangle::getPointA() const {
	return point[0];
}

Point2D Triangle::getPointB() const {
	return point[1];
}

Point2D Triangle::getPointC() const {
	return point[2];
}

void Triangle::setAx(float Ax) {
	this->point[0].x = Ax;
}

void Triangle::setAy(float Ay) {
	this->point[0].y = Ay;
}

void Triangle::setBx(float Bx) {
	this->point[1].x = Bx;
}

void Triangle::setBy(float By) {
	this->point[1].y = By;
}

void Triangle::setCx(float Cx) {
	this->point[2].x = Cx;
}

void Triangle::setCy(float Cy) {
	this->point[2].y = Cy;
}

void Triangle::setPointA(Point2D PointA) {
	this->point[0] = PointA;
}

void Triangle::setPointB(Point2D PointB) {
	this->point[1] = PointB;
}

void Triangle::setPointC(Point2D PointC) {
	this->point[2] = PointC;
}

void Triangle::setPoints(float Ax, float Ay, float Bx, float By, float Cx, float Cy) {
	point[0].x = Ax; point[0].y = Ay;
	point[1].x = Bx; point[1].y = By;
	point[2].x = Cx; point[2].y = Cy;
}

void Triangle::setPoints(Point2D p1, Point2D p2, Point2D p3) {
	point[0] = p1;
	point[1] = p2;
	point[2] = p3;
}

void Triangle::input() {
	cout << "...Enter Points of Triangle...\n";
	Polygon::input();
}

void Triangle::output() const {
	cout << "...Points of Triangle...\n";
	Polygon::output();
}