#include "GVCH.h"
#include "GVTG.h"

using namespace std;

void KhoiTaoDS(GVCH*& gvch, GVTG*& GVTG, int &nGV, int &nGVCH, int &nGVTG);
void NhapDSGV(GVCH*& gvch, GVTG*& gvtg, int nGV, int nGVCH, int nGVTG);
void XuatDSCH(GVCH* gvch, int nGVCH);
void XuatDSTG(GVTG* gvtg, int nGVTG);
long long TongLuongDSGV(GVCH* gvch, GVTG* gvtg, int nGVCH, int nGVTG);
GVCH maxLuongGVCH(GVCH* gvch, int nGVCH);
GVTG maxLuongGVTG(GVTG* gvtg, int nGVTG);
void maxLuongDSGV(GVCH* gvch, GVTG* gvtg, int nGV, int nGVCH, int nGVTG);

int main() {
	int nGVCH, nGVTG, nGV;
	GVCH* gvch;	GVTG* gvtg;
	
	KhoiTaoDS(gvch, gvtg, nGV, nGVCH, nGVTG);
	NhapDSGV(gvch, gvtg, nGV, nGVCH, nGVTG);
	XuatDSCH(gvch, nGVCH);
	XuatDSTG(gvtg, nGVTG);
	cout << "\n-> Tong tien luong cac giang vien = " << TongLuongDSGV(gvch, gvtg, nGVCH, nGVTG) << endl;
	cout << "\n...Thong tin giang vien co luong cao nhat...\n";
	maxLuongDSGV(gvch, gvtg, nGV, nGVCH, nGVTG);

	cout << endl << endl;
	delete[] gvch, gvtg;
	system("pause");
	return 0;
}

//Khởi tạo danh sách giảng viên
void KhoiTaoDS(GVCH*& gvch, GVTG*& gvtg, int &nGV, int &nGVCH, int &nGVTG) {
	cout << "Nhap so luong GVCH: "; cin >> nGVCH;
	cout << "Nhap so luong GVTG: "; cin >> nGVTG;
	nGV = nGVCH + nGVTG;
	gvch = new GVCH[nGVCH];
	gvtg = new GVTG[nGVTG];
}

//Nhập danh sách giảng viên
void NhapDSGV(GVCH*& gvch, GVTG*& gvtg, int nGV, int nGVCH, int nGVTG) {
	for (int i = 0, kGVCH = 0, kGVTG = 0; i < nGV; i++) {
		string type;
		cout << "\n...Nhap thong tin giang vien thu " << i + 1 << "...\n";
		cin.ignore();

		do {
			cout << "Nhap loai giang vien (GVCH/GVTG): ";
			getline(cin, type);
		} while (type != "GVCH" && type != "GVTG" || (type == "GVCH" && kGVCH >= nGVCH) || (type == "GVTG" && kGVTG >= nGVTG));

		if (type == "GVCH") gvch[kGVCH++].Nhap();
		else gvtg[kGVTG++].Nhap();
	}
}

//Xuất danh sách giảng viên cơ hữu
void XuatDSCH(GVCH * gvch, int nGVCH) {
	cout << "\n...Danh sach GVCH...\n";
	for (int i = 0; i < nGVCH; i++) {
		cout << "\n[GVCH thu " << i + 1 << "]" << endl;
		gvch[i].Xuat();
	}
}

//Xuất danh sách giảng viên thỉnh giảng
void XuatDSTG(GVTG * gvtg, int nGVTG) {
	cout << "\n...Danh sach GVTG...\n";
	for (int i = 0; i < nGVTG; i++) {
		cout << "\n[GVTG thu " << i + 1 << "]" << endl;
		gvtg[i].Xuat();
	}
}

//Tính tổng lương của danh sách giảng viên
long long TongLuongDSGV(GVCH * gvch, GVTG * gvtg, int nGVCH, int nGVTG) {
	long long TongTienLuong = 0;
	for (int i = 0; i < nGVCH; i++) TongTienLuong += gvch[i].getTongLuong();
	for (int i = 0; i < nGVTG; i++) TongTienLuong += gvtg[i].getTongLuong();
	return TongTienLuong;
}

//Tìm GVCH có lương cao nhất
GVCH maxLuongGVCH(GVCH * gvch, int nGVCH) {
	int vt = 0;
	for (int i = 0; i < nGVCH; i++)
		if (gvch[vt].getTongLuong() < gvch[i].getTongLuong())
			vt = i;
	return gvch[vt];
}

//Tìm GVTG có lương cao nhất
GVTG maxLuongGVTG(GVTG * gvtg, int nGVTG) {
	int vt = 0;
	for (int i = 0; i < nGVTG; i++)
		if (gvtg[vt].getTongLuong() < gvtg[i].getTongLuong())
			vt = i;
	return gvtg[vt];
}

//Tìm GV có lương cao nhất trong danh sách
void maxLuongDSGV(GVCH* gvch, GVTG* gvtg, int nGV, int nGVCH, int nGVTG) {
	long long maxLuong;
	if (!nGVCH) {
		maxLuongGVTG(gvtg, nGVTG).Xuat();
		maxLuong = maxLuongGVTG(gvtg, nGVTG).getTongLuong();
	}

	else if (!nGVTG) {
		maxLuongGVCH(gvch, nGVCH).Xuat();
		maxLuong = maxLuongGVCH(gvch, nGVCH).getTongLuong();
	}

	else {
		GVCH maxGVCH = maxLuongGVCH(gvch, nGVCH);
		GVTG maxGVTG = maxLuongGVTG(gvtg, nGVTG);
		if (maxGVCH.getTongLuong() > maxGVTG.getTongLuong()) {
			maxGVCH.Xuat();
			maxLuong = maxGVCH.getTongLuong();
		}
		else {
			maxGVTG.Xuat();
			maxLuong = maxGVTG.getTongLuong();
		}
	}
	cout << "Luong cao nhat = " << maxLuong << endl;
}