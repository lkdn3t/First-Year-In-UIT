#include "NgayThang.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	//Gán giá trị từ tham số argv
	int thang, nam;
	if (argc > 2) {
		thang = atoi(argv[1]);
		nam = atoi(argv[2]);
	}
	else {
		cout << "Khong du tham so nhap vao!";
		return 0;
	}

	//Xuất tháng và năm nhập vào
	cout << "Thang nhap vao: " << thang << "\n";
	cout << "Nam nhap vao: " << nam << "\n";

	//Tìm số ngày trong tháng của năm đó (nếu hợp lệ)
	int ngay = SoNgayTrongThang(thang, nam);
	if (ngay == -1) cout << "Thang hoac nam khong hop le!\n";
	else cout << "Thang " << thang << " nam " << nam << " co " << ngay << " ngay.\n";
	
	system("pause");
	return 1;
}