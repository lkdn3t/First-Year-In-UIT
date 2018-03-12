#include "NguyenTo.h"
#include <iostream>
#include <cmath>
using namespace std;

//Hàm kiểm tra số nguyên tố
bool ktNT(int n) {
	int can2 = sqrt(n);
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;

	for (int i = 3; i <= can2; i += 2)
		if (n % i == 0) return false;
	return true;
}

//Hàm xuất các số nguyên tố nhỏ hơn n
//Cách khác (dùng sàng số nguyên tố Ereratosthenes và không cần dùng hàm ktNT)
//Vì n lấy từ command line nên không cần &n
void XuatSNT(int n) {
	if (n < 3) {
		cout << "Khong co so nguyen to nao nho hon " << n << "\n";
		return;
	}

	cout << "Cac so nguyen to nho hon " << n << ": ";
	cout << 2;
	for (int i = 3; i < n; i += 2)
		if (ktNT(i)) cout << " " << i;
	cout << "\n";
}