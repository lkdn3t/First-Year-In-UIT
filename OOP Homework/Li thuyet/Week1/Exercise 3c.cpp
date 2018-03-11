#include <iostream>
using namespace std;

//Khai báo kiểu dữ liệu phân số, gồm tử số và mẫu số
struct PhanSo {
	int tu;
	int mau;
};

//Hàm tìm ước chung lớn nhất của hai số (dùng đệ quy)
int UCLN(int a, int b) {
	return b == 0 ? a : UCLN(b, a%b);
}

//Hàm nhập phân số
void nhapPhanSo(PhanSo &ps) {
	cout << "Nhap tu so: ";
	cin >> ps.tu;
	cout << "Nhap mau so: ";
	cin >> ps.mau;
}

//Hàm xuất phân số theo định dạng tử/mẫu
void xuatPhanSo(PhanSo ps) {
	cout << ps.tu << "/" << ps.mau << "\n";
}

//Hàm rút gọn phân số
void RutGon(PhanSo &ps) {
	int t = UCLN(ps.tu, ps.mau);
	ps.tu /= t;
	ps.mau /= t;
}

//Hàm tính tổng hai phân số
PhanSo TongPhanSo(PhanSo a, PhanSo b) {
	PhanSo Tong;
	Tong.tu  = a.tu * b.mau + b.tu * a.mau;
	Tong.mau = a.mau * b.mau;
	RutGon(Tong);
	return Tong;
}

//Hàm tính hiệu hai phân số
PhanSo HieuPhanSo(PhanSo a, PhanSo b) {
	PhanSo Hieu;
	Hieu.tu  = a.tu * b.mau - b.tu * a.mau;
	Hieu.mau = a.mau * b.mau;
	RutGon(Hieu);
	return Hieu;
}

//Hàm tính tích hai phân số
PhanSo TichPhanSo(PhanSo a, PhanSo b) {
	PhanSo Tich;
	Tich.tu  = a.tu * b.tu;
	Tich.mau = a.mau * b.mau;
	RutGon(Tich);
	return Tich;
}

//Hàm tính thương hai phân số
PhanSo ThuongPhanSo(PhanSo a, PhanSo b) {
	PhanSo Thuong;
	Thuong.tu  = a.tu * b.mau;
	Thuong.mau = a.mau * b.tu;
	RutGon(Thuong);
	return Thuong;
}

//Thực hiện yêu cầu
int main() {
	PhanSo ps1, ps2;
	//Nhập hai phân số
	cout << "Nhap phan so thu nhat:\n";
	nhapPhanSo(ps1);
	cout << "\nNhap phan so thu hai:\n";
	nhapPhanSo(ps2);

	//Xuất hai phân số
	cout << "\nPhan so thu nhat: ";
	xuatPhanSo(ps1);
	cout << "Phan so thu hai: ";
	xuatPhanSo(ps2);
	cout << "\n";

	//Xuất tổng hai phân số
	PhanSo Tong = TongPhanSo(ps1, ps2);
	cout << "Tong phan so = ";
	xuatPhanSo(Tong);

	//Xuất hiệu hai phân số
	PhanSo Hieu = HieuPhanSo(ps1, ps2);
	cout << "\nHieu phan so = ";
	xuatPhanSo(Hieu);

	//Xuất tích hai phân số
	PhanSo Tich = TichPhanSo(ps1, ps2);
	cout << "\nTich phan so = ";
	xuatPhanSo(Tich);

	//Xuất thương hai phân số
	PhanSo Thuong = ThuongPhanSo(ps1, ps2);
	cout << "\nThuong phan so = ";
	xuatPhanSo(Thuong);

	system("pause");
	return 0;
}