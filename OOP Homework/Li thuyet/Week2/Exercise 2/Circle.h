#include <iostream>
using namespace std;

#pragma once
class Circle {
private:
	//Định các thuộc tính
	//Gồm toạ độ tâm và bán kính
	struct Point2D {
		float Ox;
		float Oy;
	};

	Point2D O;
	float R;

public:
	//Định các chức năng
	//Gồm tính diện tích, chu vi và xuất kết quả
	void	inputInfo();
	float	Surface();
	float	Perimeter();
	void	printInfo();
};