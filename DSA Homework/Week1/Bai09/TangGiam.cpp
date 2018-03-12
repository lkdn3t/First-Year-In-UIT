#include "TangGiam.h"

//Hàm kiểm tra số n có giảm dần từ trái sang phải
//Kiểm tra n có tăng dần từ phải sang trái
bool ktGiamDan(int n) {
	if (n < 10) return false;
	int temp = -1;
	while (n != 0) {
		if (n % 10 <= temp) return false;
		temp = n % 10;
		n /= 10;
	} return true;
}

//Hàm kiểm tra số n có tăng dần từ trái sang phải
//Kiểm tra n có giảm dần từ phải sang trái
bool ktTangDan(int n) {
	if (n < 10) return false;
	int temp = 10;
	while (n != 0) {
		if (n % 10 >= temp) return false;
		temp = n % 10;
		n /= 10;
	} return true;
}

//Kiểm tra n có tăng dần hay giảm dần từ trái sang phải
int KTTangGiam(int n) {
	return ktGiamDan(n) ? -1 : ktTangDan(n) ? 1 : 0;
}