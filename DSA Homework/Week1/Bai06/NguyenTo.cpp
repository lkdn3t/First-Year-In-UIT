#include "NguyenTo.h"

//Kiểm tra chữ số nguyên tố (2, 3, 5, 7)
int ChuSoNT(int n) {
	switch (n) {
	case 2: case 3: case 5: case 7:
		return 1;
	default:
		return 0;
	}
}

//Kiểm tra số nhập vào chỉ chứa toàn chữ số nguyên tố
int KiemTraToanSNT(int n) {
	while (n != 0) {
		if (!ChuSoNT(n % 10)) return 0;
		n /= 10;
	} return 1;
}