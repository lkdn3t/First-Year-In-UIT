#include <iostream>
#include "SinhVien.h"
using namespace std;

int main(int argc, char* argv[]) {
	//Khởi tạo n và kiểm tra n phải số nguyên dương hay không
	int n;
	if (argc > 1) {
		n = atoi(argv[1]);
		if (n <= 0) {
			cout << "Vui long nhap so nguyen duong!\n";
			return 0;
		}
	}
	else {
		cout << "Khong du tham so nhap vao!\n";
		return 0;
	}

	//Nhập vào danh sách sinh viên và xuất danh sách
	SV* sv;
	sv = NhapDanhSachSV(n);
	XuatDanhSachSV(sv, n);

	//Tìm m sinh viên có điểm trung bình cao nhất
	int m;
	XuatDanhSachSV_DiemTBMax(sv, n, m);

	//Tìm lớp có nhiều sinh viên nhất
	string LopMaxSV = Lop_SVMax(sv, n);
	cout << "\nLop co nhieu sinh vien nhat: " << LopMaxSV <<"\n";

	delete[]sv;
	system("pause");
	return 1;
}