#include "Point2D.h"

int main() {
	Point2D A, B;
	cout << "Nhap toa do diem A:\n";
	A.inputPoint();
	cout << "\nNhap toa do diem B:\n";
	B.inputPoint();
	A.printDistance(B);

	system("pause");
	return 0;
}