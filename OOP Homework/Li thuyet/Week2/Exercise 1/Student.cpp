#include "Student.h"
#include <string>
#include <iostream>
#define if_range(x,head,tail) if (x >= head && x < tail) 
using namespace std;

//Nhập các thông tin của học sinh
//Gồm: Họ tên, Điểm văn, Điểm toán
void Student:: inputInfo() {
	cout << "Nhap ho ten: ";
	getline(cin, Name);
	cout << "Nhap diem toan: ";
	cin >> MathGrade;
	cout << "Nhap diem van: ";
	cin >> LiteratureGrade;
}

//Tính điểm trung bình của học sinh
float Student:: AverageGrade() {
	return (MathGrade + LiteratureGrade) / 2;
};

//Tìm xếp loại của học sinh
string Student:: Grade() {
	float average = AverageGrade();
	if (average < 3.0) return "Kem";
	else if_range(average, 3.0, 5.0) return "Yeu";
	else if_range(average, 5.0, 6.5) return "Trung binh";
	else if_range(average, 6.5, 8.0) return "Kha";
	else if_range(average, 8.0, 9.0) return "Gioi";
};

//In kết quả: gồm điểm trung bình và xếp loại
void Student::printInfo() {
	cout << "Diem trung binh: " << AverageGrade();
	cout << "\nXep loai: " << Grade() << "\n";
}