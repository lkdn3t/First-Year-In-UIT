#include "BCNN.h"

//Tìm ước chung lớn nhất
int USCLN(int a, int b) {
	return b == 0 ? a : USCLN(b, a%b);
}

//Tìm bội chung nhỏ nhất
int BSCNN(int a, int b) {
	return a * b / USCLN(a, b);
}