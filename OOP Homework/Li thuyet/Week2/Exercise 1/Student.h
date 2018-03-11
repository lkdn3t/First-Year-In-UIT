#include <iostream>
#include <string>
using namespace std;

#pragma once
class Student {
private:
	//Định các thuộc tính
	//Gồm: họ tên, điểm toán, điểm văn
	string	Name;
	float	MathGrade;
	float	LiteratureGrade;

public:
	//Định các phương thức
	//Gồm: tính điểm trung bình, xếp loại và xuất kết quả
	void	inputInfo();
	float	AverageGrade();
	string	Grade();
	void	printInfo();
};