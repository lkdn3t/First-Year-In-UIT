/*	Bài 3a:
	Viết chương trình nhập vào một phân số,
	rút gọn phân số và xuất kết quả.
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
	int ucln = UCLN(ps.tu, ps.mau);
	ps.tu /= ucln;
	ps.mau /= ucln;
}

//Thực hiện yêu cầu
int main() {
	//Yêu cầu nhập phân số
	PhanSo ps;
	nhapPhanSo(ps);
	
	//Xuất phân số đã nhập
	cout << "Phan so da nhap: ";
	xuatPhanSo(ps);

	//Xuất phân số rút gọn
	cout << "Phan so rut gon: ";
	RutGon(ps);
	xuatPhanSo(ps);

	system("pause");
	return 0;
}