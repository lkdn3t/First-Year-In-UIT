#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point2D
{
private:
	//Định thuộc tính
	//Gồm hoành độ và tung độ
	int x;
	int y;

public:
	//Định chức năng
	Point2D getPoint();
	void	setPoint();
	void	printPoint();
	Point2D	MovedPoint(Point2D);
	float	Distance(Point2D);
	bool	isInLine(int, int);
};

