#include "NguyenTo.h"
#include <iostream>
using namespace std;

//Phân tích một số thành thừa số nguyên tố
//Biến isWrite dùng để xét đã viết thừa số nào lúc đầu chưa (tránh dư dấu *)
void ThuaSoNT(int n) {
	bool isWrite = false;
	cout << n << " = ";
	//Nếu n là số chẵn thì chia liên tiếp cho 2
	if (n % 2 == 0) {
		isWrite = true;
		int dem = 0;
		while (n % 2 == 0) {
			n /= 2;
			dem++;
		}
		cout << "2^" << dem;
	}

	//Đến khi n là lẻ thì chia cho các số lẻ (3, 5, 7...) cho đến khi n = 1
	//Chắc chắn khi chia thì số bị chia luôn là nguyên tố vì
	//Vì các hợp số như 15, 21 đã bị 3, 5, 7... triệt tiêu trước đó
	int div = 3;
	while (n != 1) {
		int dem = 0;
		while (n % div == 0) {
			n /= div;
			dem++;
		}
		
		if (isWrite && dem) cout << "*";
		if (dem) {
			cout << div << "^" << dem;
			isWrite = true;
		}
		div += 2;
	}
	cout << "\n";
}