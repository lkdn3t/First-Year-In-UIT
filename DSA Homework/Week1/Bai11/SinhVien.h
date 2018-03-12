#include <string>
using namespace std;

struct NGAY {
	int ngay;
	int thang;
	int nam;
};

struct SV {
	string MSSV;
	string TenSV;
	string DiaChi;
	string Lop;
	NGAY NgaySinh;
	float Toan;
	float Tin;
	float AV;
};

void NhapNgaySinh(NGAY&);
void NhapSV(SV&);
void XuatSV(SV);
SV* NhapDanhSachSV(int);
void XuatDanhSachSV(SV*, int);
void XuatDanhSachSV_DiemTBMax(SV*, int, int&);
string Lop_SVMax(SV*, int);