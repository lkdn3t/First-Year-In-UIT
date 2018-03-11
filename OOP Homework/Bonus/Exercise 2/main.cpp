#include "Set.h"
#include <iostream>
using namespace std;

int main() {
	//Khởi tạo hai tập hợp A, B nhập từ bàn phím
	Set A, B;
	A.setElements();
	B.setElements();

	//In các tập hợp theo yêu cầu
	A.printSet();
	B.printSet();
	A.Intersect(B).printSet();
	A.Union(B).printSet();

	system("pause");
	return 0;
}