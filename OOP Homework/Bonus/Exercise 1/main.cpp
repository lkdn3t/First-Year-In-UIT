//Link đề bài: https://goo.gl/m1gzHV

#include "Point2D.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//Khởi tạo hai giá trị điểm A, B
	//Lấy a, b của phương trình ax + by = 0
	Point2D A, B;
	int a, b;
	A.setPoint();
	B.setPoint();
	cin >> a >> b;

	//In hai điểm A, B
	A.printPoint();
	B.printPoint();
	
	//Thực hiện các yêu cầu
	A.MovedPoint(B).printPoint();								
	cout << fixed << setprecision(1) << A.Distance(B) << "\n";
	A.isInLine(a, b) ? cout << "YES" : cout << "NO";

	system("pause");
	return 0;
}