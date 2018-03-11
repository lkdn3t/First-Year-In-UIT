/*	Bài 3b:
	Viết chương trình nhập vào hai phân số,
	tìm phân số lớn nhất và xuất kết quả.
*/

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

//Hàm tìm bội chung nhỏ nhất của hai số
int BCNN(int a, int b) {
	return a * b / UCLN(a, b);
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

//Hàm so sánh hai phân số
//Quy đồng phân số và so sánh tử, bản chất là nhân 2 tử cho t và so sánh
//Với t = BCNN(mẫu1, mẫu2) / mẫu tương ứng của mỗi phân số
int SoSanh(PhanSo ps1, PhanSo ps2) {
	int t1 = BCNN(ps1.mau, ps2.mau) / ps1.mau;
	int t2 = BCNN(ps1.mau, ps2.mau) / ps2.mau;
	int cmp = ps1.tu*t1 - ps2.tu*t2;
	return cmp > 0 ? 1 : cmp == 0 ? 0 : -1;
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

	//So sánh và xuất ra phân số lớn hơn
	int cmp = SoSanh(ps1, ps2);
	if (cmp == 0) cout << "Hai phan so bang nhau\n";
	else {
		cout << "Phan so lon hon = ";
		cmp > 0 ? xuatPhanSo(ps1) : xuatPhanSo(ps2);
	}

	system("pause");
	return 0;
}