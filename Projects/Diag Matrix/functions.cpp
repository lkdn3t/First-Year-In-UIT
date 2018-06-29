#include <cmath>
#include <iostream>
#include <cstdlib>
#include "functions.h"
#define pi 3.14159265359
#define eps 0.0000001
#define GachNgang cout << "________________________________________________" << endl << endl
using namespace std;

//Tìm số nghiệm của phương trình bậc hai
//Dùng tìm số trị riêng của ma trận 2x2
int SoTriRiengMT2(int a, int b, int c) {
	int delta = b*b - 4 * a*c;
	if (delta < 0)
		return 0;
	else if (delta == 0)
		return 1;
	else
		return 2;
}

//Giải phương trình bậc hai
//Dùng tìm trị riêng cho ma trận 2x2
float x1_MT2, x2_MT2, x_MT2;
void TimTriRiengMT2(int a, int b, int c)
{
	int delta = b*b - 4 * a*c;

	if (delta == 0) {
		float x_MT2 = (float)-b / (2 * a);
		cout << " [x] = " << x_MT2 << endl;
	}
	else if (delta > 0) {
		x1_MT2 = (-b + (float)sqrt(delta)) / (2 * a);
		x2_MT2 = (-b - (float)sqrt(delta)) / (2 * a);
		if (x1_MT2 > x2_MT2) swap(x1_MT2, x2_MT2);

		cout << " [x1] = " << x1_MT2 << endl << endl;
		cout << " [x2] = " << x2_MT2 << endl;
	}
}

//Tìm số nghiệm phương trình bậc ba
//Dùng tìm số trị riêng của ma trận 3x3
int SoTriRiengMT3(int a, int b, int c, int d) {
	long denta = b*b - 3 * a*c;
	long tritd = abs(denta);
	if (denta > 0)
	{
		long tu = 9 * a*b*c - 2 * (long)pow(b, 3) - 27 * a*a*d;
		double mau = 2 * sqrt(pow(tritd, 3));
		double k = tu / mau;

		if (abs(k) <= 1)
			return 3;
		else
			return 1;
	}
	else
		return 1;
}

//Giải phương trình bậc ba
//Dùng tìm trị riêng cho ma trận 3x3
void TimTriRiengMT3(int a, int b, int c, int d) {
	long delta; double k;
	//Tính delta & k
	delta = b*b - 3 * a*c;
	k = (9 * a*b*c - 2 * pow(b, 3.0) - 27 * a*a*d) / (2 * sqrt(pow(abs(delta), 3.0)));
	//TH1: Delta < 0 phương trình có 1 nghiệm
	if (delta < 0) {
		double x, can3, check;
		can3 = pow((k + sqrt(k*k + 1)), 1 / 3.0);
		//check xem a trong hàm pow >0 hay không:
		check = (k - sqrt(k*k + 1));
		if (check >= 0) can3 += pow(check, 1 / 3.0);
		else can3 -= pow(-check, 1 / 3.0);

		// Tính x
		double tu = (sqrt(abs(delta))*can3 - b);
		long mau = 3 * a;
		x = tu / mau;
		cout << " Ma tran co 1 tri rieng: " << endl << endl;
		cout << " [x] = " << x << endl << endl;
	}

	//TH2: Delta = 0 -> Pt có nghiệm bội
	else if (delta == 0) {
		double x;
		long check = b*b*b - 27 * a*a*d;

		if (check >= 0)
			x = (-b + pow(check, 1 / 3.0)) / (3 * a);
		else
			x = (-b - pow(-check, 1 / 3.0)) / (3 * a);
		cout << " Ma tran co 1 tri rieng: " << endl << endl;
		cout << " [x] = " << x << endl << endl;
	}


	//TH3: Delta > 0 -> xét từng trường hợp k
	else {
		// abs(k) > 1 => Phương trình có 1 nghiệm duy nhất
		if (abs(k) > 1) {
			//Thực hiện tính căn3 như ở TH1
			double can3 = pow(k + sqrt(k*k + 1), 1.0 / 3);
			double check = k - sqrt(k*k + 1);
			if (check >= 0) can3 += pow(check, 1.0 / 3);
			else can3 -= pow(-check, 1.0 / 3);

			//Tính x
			double tu = sqrt(delta)*abs(k)*can3 - b*k;
			double mau = 3 * a*k;
			double x = tu / mau;
			cout << " Ma tran co 1 tri rieng: " << endl << endl;
			cout << " [x] = " << x << endl << endl;
		}
		//TH abs(k) <= 1 -> Phương trình có 3 nghiệm phân biệt
		else
		{
			//Tính các cosin và căn2 = sqrt(delta)
			double cosin1 = cos(acos(k) / 3);
			double cosin2 = cos(acos(k) / 3 - 2 * pi / 3);
			double cosin3 = cos(acos(k) / 3 + 2 * pi / 3);
			double can2 = sqrt(delta);

			//Tính tử, mẫu của x
			double tu1 = 2 * can2*cosin1 - b;
			double tu2 = 2 * can2*cosin2 - b;
			double tu3 = 2 * can2*cosin3 - b;
			long mau = 3 * a;

			//Tính x1 , x2 , x3
			double x1 = tu1 / mau;
			double x2 = tu2 / mau;
			double x3 = tu3 / mau;

			//Kiểm tra điều kiện = 0 (bị lỗi kiểu dữ liệu double và long)
			if (d == 0) {
				if (fabs(x1 - (int)x1) <= eps) x1 = (int)x1;
				if (fabs(x2 - (int)x2) <= eps) x2 = (int)x2;
				if (fabs(x3 - (int)x3) <= eps) x3 = (int)x3;
			}

			//Nếu x1 trùng x2
			if (fabs(x1 - x2) <= eps)
			{
				cout << " Ma tran co 2 tri rieng: " << endl << endl;
				cout << " [x1] = " << x1 << endl << endl;
				cout << " [x2] = " << x3 << endl << endl;
			}
			//Nếu x1 trùng x3
			else if (fabs(x2 - x3) <= eps)
			{
				cout << " Ma tran co 2 tri rieng: " << endl << endl;
				cout << " [x1] = " << x1 << endl << endl;
				cout << " [x2] = " << x2 << endl << endl;
			}

			//Nếu x2 trùng x3
			else if (fabs(x1 - x3) <= eps)
			{
				cout << " Ma tran co 2 tri rieng: " << endl << endl;
				cout << " [x1] = " << x2 << endl << endl;
				cout << " [x2] = " << x3 << endl << endl;
			}

			//Nếu là 3 nghiệm phân biệt
			else
			{
				cout << " Ma tran co 3 tri rieng: " << endl << endl;
				cout << " [x1] = " << x1 << endl << endl;
				cout << " [x2] = " << x2 << endl << endl;
				cout << " [x3] = " << x3 << endl << endl;
			}
		}
	}
}

//Nhập ma trận vuông cỡ n
void NhapMaTran(int a[][3], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap hang thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++) cin >> a[i][j];
		cout << endl;
	}
	GachNgang;
}

//Kiểm tra tính hợp lệ của ma trận nhập vào
//Ma trận nhập không được là ma trận 0
bool KTKhong(int a[][3], int n) {
	bool kt = false;
	
	//Đếm số phần tử bằng không trong ma trận
	int dem = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (a[i][j] == 0) dem += 1;
	}

	//Nếu dem = n*n thì đó là ma trận 0
	if (dem == n*n) kt = true;
	return kt;
}

//Kiểm tra ma trận nhập vào đã là ma trận chéo hay chưa
bool KTCheo(int a[][3], int n) {
	int dem = 0;

	//Đếm số lượng phần tử bằng 0 và không nằm trên đường chéo chính
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == j) continue;
			else if (a[i][j] == 0) dem += 1;
	}

	//Nếu số lượng phần tử đã đếm = n*(n-1) thì ma trận đó là ma trận chéo
	//VD: MT2 thì dem == 2 ; MT3 thì dem == 6
	if (dem == n*(n - 1)) return true;
	else return false;
}

//Kiểm tra ma trận 2x2 nhập vào phải ma trận đối xứng hay không
bool KTDoiXung(int a[][3], int n) {
	if (a[0][0] == a[1][1] && a[0][1] == a[1][0]) return true;
	else return false;
}

//Xuất ma trận đã nhập
void XuatMaTran(int a[][3], int n) {
	cout << " Ma tran da nhap:" << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << "   " << a[i][j];
		cout << endl << endl;
	}
	GachNgang;
}

//Xuất ma trận chéo cỡ n nếu có
void MaTranCheo(int a[][3], int n) {
	for (int i = 0; i < n; i++) {
		cout << "  ";
		for (int j = 0; j < n; j++) {
			if (i == j) cout << "[x" << i + 1 << "] ";
			else cout << 0 << "  ";
			cout << "  ";
		}
		cout << endl << endl;
	}
}

/*
Tìm vectơ cơ sở của ma trận 2x2
Thực chất là giải hệ:
(1): Ax = By (với A = lamda - a ; B = b)
(2): Cx = Dy (với C = c ; D = lamda - d)
=> Để tồn tại nghiệm thì A/C = B/D hoặc một trong hai phương trình là vô số nghiệm
*/

//Dùng để chứa các vectơ để tận dụng tìm cơ sở trực chuẩn trong chéo hoá trực giao
float v[4];
int t = 0;

void VectoMT2(float a, int b, int c, float d) {
	//Reset lại biến đếm t nếu như thực hiện nhiều lần yêu cầu
	//Vì mỗi lần thực hiện tìm trị riêng sẽ tạo ra 4 biến mới
	//Nên cho t = 0 là gắn lại từ đầu các biến, tránh bị tràn mảng
	if (t >= 4) t = 0;

	//Xét A và B khác 0 và (2) vô số nghiệmm
	if (a != 0 && b != 0) {
		if (abs(a) > abs(b)) {
			v[t++] = 1;
			v[t++] = a / b;
		}
		else {
			v[t++] = b / a;
			v[t++] = 1;
		}
		cout << "(" << v[t-2] << " ; " << v[t-1] << ")";
	}

	//Xét C và D khác 0 và (1) vô số nghiệm
	else if (c != 0 && d != 0) {
		if (abs(c) > abs(d)) {
			v[t++] = 1;
			v[t++] = c / d;
		}
		else {
			v[t++] = d / c;
			v[t++] = 1;
		}
		cout << "(" << v[t-2] << " ; " << v[t-1] << ")";
	}

	//Xét B và D đều bằng 0 => x = 0 và y tuỳ ý
	else if (b == 0 && d == 0)
		cout << "(0 ; 1)";

	//Xét A và C đều bằng 0 => x tuỳ ý và y = 0
	else if (a == 0 && c == 0)
		cout << "(1 ; 0)";
}

//Yêu cầu họn lại yêu cầu khác của bảng chọn nếu muốn
void ChonLai() {
	char c;
	do {
		cout << " Thuc hien yeu cau khac? (Y/N): ";
		cin >> c;
	} while (c != 'N' && c != 'Y');

	if (c == 'Y') {
		system("cls");
		BangChon();
	}
	else exit(0);
}

//Xuất các trị riêng của ma trận 2x2
//Thực chất là giải pt bậc 2 sau khi khai triển: AX^2 + BX + C = 0
//Với A = 1 ; B = a + d ; C = ad - bc
void Xuat_TriRiengMT2(int a[][3], int n) {
	int b = -(a[0][0] + a[1][1]);
	int c = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	cout << " Ma tran co " << SoTriRiengMT2(1, b, c) << " tri rieng:" << endl << endl;
	TimTriRiengMT2(1, b, c);
}

//Xuất các vectơ cơ sở của ma trận 2x2
//Căn cứ vào số trị riêng => Tìm số vectơ cơ sở
void Xuat_VectoMT2(int a[][3], int n) {
	int b = -(a[0][0] + a[1][1]);
	int c = a[0][0] * a[1][1] - a[0][1] * a[1][0];

	//TH1: Có 2 trị riêng => Tìm 2 vectơ cơ sở
	if (SoTriRiengMT2(1, b, c) == 2) {
		cout << " Ma tran co 2 vecto co so: " << endl << endl;
		cout << " [v1] = ";
		VectoMT2(x1_MT2 - a[0][0], a[0][1], a[1][0], x1_MT2 - a[1][1]);
		cout << endl << endl << " [v2] = ";
		VectoMT2(x2_MT2 - a[0][0], a[0][1], a[1][0], x2_MT2 - a[1][1]);
	}

	//TH2: Có 1 trị riêng => Tìm 1 vectơ cơ sở
	else if (SoTriRiengMT2(1, b, c) == 1) {
		cout << " Ma tran co 1 vecto co so: " << endl << endl;
		cout << " [v] = ";
		VectoMT2(x_MT2 - a[0][0], a[0][1], a[1][0], x_MT2 - a[1][1]);
	}

	//TH3: Không có trị riêng => Không có vectơ cơ sở
	else cout << " Ma tran khong co vecto co so.";
	cout << endl << endl;
}

//Xuất ra ma trận chéo hoá (nếu có) của ma trận 2x2 nhập vào
void Xuat_MT2Cheo(int a[][3], int n) {
	int b = -(a[0][0] + a[1][1]);
	int c = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	if (SoTriRiengMT2(1, b, c) == 2) {
		//Xuất ma trận P^(-1)*A*P
		cout << " Ma tran cheo P^(-1)*A*P: " << endl << endl;
		MaTranCheo(a, 2);
	}
	else
		//Nếu không đủ 2 trị riêng => Không có đủ 2 vectơ cơ sở
		cout << " Khong the cheo hoa ma tran" << endl << endl;
}

//YÊU CẦU 1: CHÉO HOÁ MA TRẬN 2X2
void CheoHoaMT2() {
	//In dòng giới thiệu
	cout << "\t   ***CHEO HOA MA TRAN 2X2***" << endl << endl;
	GachNgang;

	//Nhập và xuất ma trận vừa nhập
	int a[3][3];
	NhapMaTran(a, 2);
	XuatMaTran(a, 2);

	//Nếu ma trận nhập vào có hàng bằng 0
	//Không hợp lệ, xuất ra thông báo
	if (KTKhong(a, 2)) {
		cout << " Ma tran nhap vao la ma tran khong" << endl;
		GachNgang;
		return ChonLai();
	}

	//Nếu ma trận nhập vào là ma trận chéo
	//Chỉ cần xuất cac trị riêng và kết luận
	if (KTCheo(a, 2)) {
		Xuat_TriRiengMT2(a, 2);
		GachNgang;
		cout << " Ma tran nhap vao la ma tran cheo" << endl;
		GachNgang;
		return ChonLai();
	}

	//B1: TÌM TRỊ RIÊNG CỦA MA TRẬN
	Xuat_TriRiengMT2(a, 2);
	GachNgang;

	//B2: TÌM VECTƠ CƠ SỞ CỦA MA TRẬN
	Xuat_VectoMT2(a, 2);
	GachNgang;

	//B3: XUẤT MA TRẬN CHÉO (NẾU CÓ)
	Xuat_MT2Cheo(a, 2);
	GachNgang;
	ChonLai();
}

//Xuất trị riêng ma trận bậc 3
//Tức là giải pt bậc 3 sau khi khai triển det(A - lamda[i]) = 0
void Xuat_TriRiengMT3(int a[][3], int n) {
	int A = a[0][0], B = a[0][1], C = a[0][2];
	int D = a[1][0], E = a[1][1], F = a[1][2];
	int G = a[2][0], H = a[2][1], I = a[2][2];
	int b = A + E + I;
	int c = C*G + H*F + B*D - A*E - A*I - E*I;
	int d = A*E*I + B*F*G + C*D*H - C*G*E - A*H*F - B*D*I;
	TimTriRiengMT3(-1, b, c, d);
}

//YÊU CẦU 2: TÌM TRỊ RIÊNG CỦA MA TRẬN 3X3
void TriRiengMT3() {
	//In dòng giới thiệu
	cout << "\t***TIM TRI RIENG MA TRAN 3X3***" << endl << endl;
	GachNgang;

	//Nhập và xuất ma trận vừa nhập
	int a[3][3];
	NhapMaTran(a, 3);
	XuatMaTran(a, 3);

	//Nếu ma trận nhập vào là ma trận 0 => Không thực hiện
	if (KTKhong(a, 3)) {
		cout << " Ma tran nhap la ma tran khong" << endl;
		GachNgang;
		return ChonLai();
	}	

	//Thực hiện tìm trị riêng MTB3
	Xuat_TriRiengMT3(a, 3);

	//Nếu ma trận nhập vào là ma trận chéo
	if (KTCheo(a, 3)) {
		cout << " Ma tran nhap vao la ma tran cheo" << endl;
	}

	GachNgang;
	ChonLai();
}

//Xuất cơ sở trực chuẩn của ma trận đối xứng 2x2
//Bằng cách lấy từng toạ độ / độ dài p
//Độ dài p = sqrt(x*x + y*y)
void Xuat_CSTCMT2(int a[][3], int n) {
	float p1_1, p2_1, p_1;
	float p1_2, p2_2, p_2;

	//Tìm cơ sở trực giao 1 dựa vào cơ sở vectơ 1
	p_1 = sqrt(v[0] * v[0] + v[1] * v[1]);
	p1_1 = v[0] / p_1;
	p2_1 = v[1] / p_1;
	
	////Tìm cơ sở trực giao 1 dựa vào cơ sở vectơ 1
	p_2 = sqrt(v[2] * v[2] + v[3] * v[3]);
	p1_2 = v[2] / p_2;
	p2_2 = v[3] / p_2;

	//Xuất các cơ sở trực chuẩn
	cout << " Cac co so truc chuan:" << endl << endl;
	cout << " [p1] = " << "(" << p1_1 << " ; " << p2_1 << ")" << endl << endl;
	cout << " [p2] = " << "(" << p1_2 << " ; " << p2_2 << ")" << endl << endl;
}

//YÊU CẦU 3: CHÉO HOÁ MA TRẬN TRỰC GIAO 2X2
void CheoHoaTG() {
	cout << "      ***CHEO HOA TRUC GIAO MA TRAN 2X2***" << endl << endl;
	GachNgang;

	//Nhập và xuất ma trận đã nhập
	int a[3][3];
	NhapMaTran(a, 2);
	XuatMaTran(a, 2);

	//Nếu ma trận nhập vào là ma trận không => Không thực hiện
	if (KTKhong(a, 2)) {
		cout << " Ma tran nhap la ma tran khong" << endl;
		GachNgang;
		return ChonLai();
	}

	//Kiểm tra tính đối xứng của ma trận nhập vào
	if (!KTDoiXung(a,2)) {
		cout << " Ma tran nhap vao khong doi xung." << endl;
		GachNgang;
		return ChonLai();
	}

	//Nếu ma trận nhập vào đã chéo hoá trực giao
	if (KTCheo(a, 2)) {
		cout << " Ma tran nhap vao da cheo hoa truc giao." << endl;
		GachNgang;
		return ChonLai();
	}

	//B1: TÌM TRỊ RIÊNG CỦA MA TRẬN
	Xuat_TriRiengMT2(a, 2);
	GachNgang;

	//B2: TÌM VECTƠ CƠ SỞ CỦA MA TRẬN
	Xuat_VectoMT2(a, 2);
	GachNgang;

	//B3: TÌM CƠ SỞ TRỰC CHUẨN
	Xuat_CSTCMT2(a, 2);
	GachNgang;

	//B4: XUẤT MA TRẬN CHÉO
	Xuat_MT2Cheo(a, 2);
	GachNgang;
	ChonLai();
}

//Bảng chọn thực hiện một trong ba yêu cầu
void BangChon() {
	cout << " Bang chon yeu cau: " << endl << endl;
	cout << " 1. Cheo hoa ma tran 2x2." << endl << endl;
	cout << " 2. Tim tri rieng ma tran 3x3." << endl << endl;
	cout << " 3. Cheo hoa truc giao ma tran 2x2." << endl << endl;
	cout << " 4. Thoat chuong trinh." << endl << endl;

	//Nhập yêu cầu cần chọn
	int choose;
	do {
		cout << " Chon yeu cau (1/2/3/4): ";
		cin >> choose;
	} while (choose < 1 || choose > 4);

	//Xoá màn hình sau khi chọn xong yêu cầu
	system("cls");

	//Thực hiện theo yêu cầu
	switch (choose) {
	case 1: {
		CheoHoaMT2();
		break;
	}

	case 2: {
		TriRiengMT3();
		break;
	}
	
	case 3: {
		CheoHoaTG();
		break;
	}

	case 4:
		exit(0);
		break;
	}
}