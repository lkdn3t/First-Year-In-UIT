#include <iostream>
#include <string>
#include "SinhVien.h"
using namespace std;

//Nhập ngày tháng năm sinh
void NhapNgaySinh(NGAY& d) {
	cout << "\tNhap ngay: ";
	cin >> d.ngay;
	cout << "\tNhap thang: ";
	cin >> d.thang;
	cout << "\tNhap nam: ";
	cin >> d.nam;
}

//Nhập thông tin 1 sinh viên
void NhapSV(SV& sv) {
	cout << "- Nhap MSSV: "       ; getline(cin, sv.MSSV);
	cout << "- Nhap Ten SV: "     ; getline(cin, sv.TenSV);
	cout << "- Nhap Dia chi: "    ; getline(cin, sv.DiaChi);
	cout << "- Nhap Ngay sinh:\n" ; NhapNgaySinh(sv.NgaySinh);
	cin.ignore();
	cout << "- Nhap Lop: "        ;	getline(cin, sv.Lop);
	cout << "- Nhap Diem Toan: "  ; cin >> sv.Toan;
	cout << "- Nhap Diem Tin: "   ; cin >> sv.Tin;
	cout << "- Nhap Diem AV: "    ; cin >> sv.AV;
	cin.ignore();
}

//Xuất thông tin của 1 sinh viên
void XuatSV(SV sv) {
	cout << "- MSSV: "			<< sv.MSSV;
	cout << "\n- Ten SV: "		<< sv.TenSV;
	cout << "\n- Dia chi: "		<< sv.DiaChi;
	cout << "\n- Lop: "			<< sv.Lop;
	cout << "\n- Ngay sinh: "	<< sv.NgaySinh.ngay << "/" << sv.NgaySinh.thang << "/" << sv.NgaySinh.nam;
	cout << "\n- Diem toan: "	<< sv.Toan;
	cout << "\n- Diem tin: "	<< sv.Tin;
	cout << "\n- Diem AV: "		<< sv.AV << "\n";
}

//Nhập danh sách sinh viên (dùng mảng động)
SV* NhapDanhSachSV(int n) {
	SV *sv = new SV[n];
	for (int i = 0; i < n; ++i) {
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
		NhapSV(sv[i]);
	}
	return sv;
}

//Xuất danh sách sinh viên
void XuatDanhSachSV(SV* sv, int n) {
	for (int i = 0; i < n; ++i) {
		cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
		XuatSV(sv[i]);
	}
}

//Xuất danh sách m sinh viên có điểm trung bình cao nhất trong danh sách
void XuatDanhSachSV_DiemTBMax(SV* sv, int n, int &m) {
	//Nhập số sinh viên cần tìm điểm trung bình cao nhất
	cout << "\nNhap so sinh vien can xep hang diem trung binh: ";
	cin >> m;
	while (m > n) {
		cout << "So sinh vien phai nho hon " << n << "\n";
		cout << "Nhap lai so sinh vien can xep hang diem trung binh: ";
		cin >> m;
	}

	//Tính điểm trung bình của n sinh viên
	float *dtb = new float[n];
	for (int i = 0; i < n; ++i)
		dtb[i] = (sv[i].Toan + sv[i].Tin + sv[i].AV) / 3;

	//Lần lượt tìm m điểm trung bình cao nhất và xuất ra sinh viên tương ứng
	int k = 0;
	float dtbMax = 11;

	//Tìm đtb cao thứ 1 rồi tìm số sinh viên có điểm trung bình cao 1 và xuất thông tin
	//Tương tự với đtb cao thứ 2, 3... cho đến khi con chạy k = m (đủ số sv) thì ngưng
	cout << "-> Danh sach " << m << " sinh vien co diem trung binh cao nhat:";
	while(k < m) {
		//Mỗi lần lặp thì dtbMax sẽ đổi giới hạn để tìm đtb cao thứ 1, 2...
		float tempMax = 11;
		for (int i = 0; i < n; ++i)
			if ((dtb[i] > tempMax || tempMax == 11) && dtb[i] < dtbMax)
				tempMax = dtb[i];
		dtbMax = tempMax;
		
		//Xuất (các) sinh viên có đtb cao thứ 1, 2... tương ứng
		for (int i = 0; i < n; ++i) {
			if (dtb[i] == tempMax) {
				cout << "\n...Sinh vien thu " << ++k << "...";
				cout << "\n- MSSV: "	<< sv[i].MSSV;
				cout << "\n- Ten SV: "	<< sv[i].TenSV;
				cout << "\n- Lop: "		<< sv[i].Lop;
				cout << "\n- Diem TB: " << dtb[i] << "\n";
			}
		}
	}
	delete[]dtb;
}

//Tìm lớp có nhiều sinh viên nhất
//Dùng mảng lưu các lớp riêng biệt, đếm từng lớp và trả kết quả
string Lop_SVMax(SV* sv, int n) {
	string *DSLop = new string[n];
	int k = 0;

	//Mảng DSLop dùng lưu các lớp riêng biệt (không trùng tên)
	for (int i = 0; i < n; ++i) {
		bool flag = true;
		for (int j = 0; j < i; ++j)
			if (sv[i].Lop == sv[j].Lop) {
				flag = false;
				break;
			}
		if (flag) DSLop[k++] = sv[i].Lop;
	}

	//Tìm lớp có sinh viên nhiều nhất (đếm lớp xuất hiện nhiều sinh viên nhất)
	int vt = 0;
	int maxLop = 0;

	for (int i = 0; i < k; ++i) {
		int dem = 0;
		for (int j = 0; j < n; ++j)
			if (sv[j].Lop == DSLop[i]) ++dem;

		if (dem > maxLop) {
			maxLop = dem;
			vt = i;
		}
	}
	string kq = DSLop[vt];
	delete[]DSLop;
	return kq;
}