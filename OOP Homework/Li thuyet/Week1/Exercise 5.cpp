#include <iostream>
#include <string>
using namespace std;

//Tạo struct nhân viên gồm các thông tin
//Mã nhân viên ; Họ tên ; Phòng ban ; Lương cơ bản ; Thưởng
struct NhanVien {
	string MaNhanVien;
	string HoTen;
	string PhongBan;
	long LuongCoBan;
	long Thuong;
};

//Tính thực lãnh của nhân viên = Lương cơ bản + Thưởng
long ThucLanh(NhanVien nv) {
	return nv.LuongCoBan + nv.Thuong;
}

//Nhập các thông tin của nhân viên
void NhapNhanVien(NhanVien &nv) {
	cin.ignore();
	cout << "- Nhap ma nhan vien: ";
	getline(cin, nv.MaNhanVien);
	cout << "- Nhap ho ten: ";
	getline(cin, nv.HoTen);
	cout << "- Nhap phong ban: ";
	getline(cin, nv.PhongBan);
	cout << "- Nhap luong co ban: ";
	cin >> nv.LuongCoBan;
	cout << "- Nhap thuong: ";
	cin >> nv.Thuong;
}

//Xuất các thông tin của nhân viên
void XuatNhanVien(NhanVien nv) {
	cout << "\n- Ma nhan vien: " << nv.MaNhanVien;
	cout << "\n- Ho ten: " << nv.HoTen;
	cout << "\n- Phong ban: " << nv.PhongBan;
	cout << "\n- Luong co ban: " << nv.LuongCoBan;
	cout << "\n- Thuong: " << nv.Thuong << "\n";
}

//Nhập vào danh sách nhân viên (dùng mảng động)
void NhapDSNV(NhanVien *&nv, int &n) {
	cout << "Nhap so luong nhan vien: ";
	cin >> n;

	nv = new NhanVien[n];
	for (int i = 0; i < n; ++i) {
		cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
		NhapNhanVien(nv[i]);
	}
}

//Xuất ra danh sách nhân viên
void XuatDSNV(NhanVien *nv, int n) {
	for (int i = 0; i < n; ++i) {
		cout << "\n\nThong tin nhan vien thu " << i + 1 << ":";
		XuatNhanVien(nv[i]);
	}
}

//Yêu cầu a: Xuất ra thực lãnh của từng nhân viên
void XuatThucLanh(NhanVien *nv, int n) {
	cout << "\nThuc lanh cac nhan vien:\n";
	for (int i = 0; i < n; ++i)
		cout << "- Thuc lanh nhan vien " << nv[i].HoTen << " = " << ThucLanh(nv[i]) << "\n";
}

//Yêu cầu b: Xuất (các) nhân viên có mức lương cơ bản thấp nhất
void XuatLCB_Min(NhanVien *nv, int n) {
	//Tìm mức lương cơ bản thấp nhất
	long minLCB = nv[0].LuongCoBan;
	for (int i = 0; i < n; ++i)
		if (minLCB > nv[i].LuongCoBan) minLCB = nv[i].LuongCoBan;

	//Xuất ra các nhân viên có mức lương cơ bản thấp nhất
	for (int i = 0; i < n; ++i)
		if (nv[i].LuongCoBan == minLCB) {
			XuatNhanVien(nv[i]);
			cout << "\n";
		}
}

//Yêu cầu c: Đếm các nhân viên có mức lương thưởng hơn 1m2
int DemNhanVien(NhanVien *nv, int n) {
	int dem = 0;
	for (int i = 0; i < n; ++i)
		if (nv[i].Thuong >= 1200000) ++dem;
	return dem;
}

//Yêu cầu d: Xuất các nhân viên theo phòng ban
//Nếu trùng phòng ban thì xuất theo mã số nhân viên giảm dần
void NVTheoPB(NhanVien *nv, int n) {
	//Bước 1: Tạo mảng chứa danh sách các phòng ban riêng biệt
	string DSPhongBan[100];
	int k = 0;
	
	for (int i = 0; i < n; ++i) {
		bool flag = true;
		for (int j = 0; j < k; ++j)
			if (nv[i].PhongBan == DSPhongBan[j]) {
				flag = false;
				break;
			}
		if (flag) DSPhongBan[k++] = nv[i].PhongBan;
	}

	//Bước 2: Với mỗi phòng ban, tạo mảng lưu nhân viên trong phòng ban đó
	//Sau đó sắp xếp lại các nhân viên theo mã số nhân viên giảm dần
	for (int i = 0; i < k; ++i) {
		NhanVien nv_tmp[100];
		int t = 0;

		//Đưa các nhân viên vào mảng tương ứng với phòng ban
		for (int j = 0; j < n; ++j)
			if (nv[j].PhongBan == DSPhongBan[i]) nv_tmp[t++] = nv[j];

		//Sắp xếp lại theo mã nhân viên
		for (int j = 0; j < t - 1; ++j)
			for (int p = j + 1; p < t; ++p)
				if (nv_tmp[j].MaNhanVien < nv_tmp[p].MaNhanVien)
					swap(nv_tmp[j], nv_tmp[p]);

		//Xuất ra các nhân viên sau khi sắp xếp theo phòng ban tương ứng
		cout << "\nDanh sach nhan vien theo phong ban " << DSPhongBan[i] << "\n";
		for (int j = 0; j < t; ++j) XuatNhanVien(nv_tmp[j]);
	}
}

//Tạo bảng chọn thực hiện các yêu cầu
void BangChon(NhanVien *&nv, int &n) {
	int choose;
	cout << "1. Nhap danh sach nhan vien.";
	cout << "\n\n2. Xuat danh sach nhan vien.";
	cout << "\n\n3. Xuat thuc lanh cac nhan vien.";
	cout << "\n\n4. Xuat cac nhan vien co luong co ban thap nhat.";
	cout << "\n\n5. Dem so luong nhan vien co muc thuong >= 1200000.";
	cout << "\n\n6. Xuat danh sach nhan vien theo phong ban.";
	cout << "\n\n0. Thoat.";
	cout << "\n\nChon yeu cau: ";
	cin >> choose;
	system("cls");

	switch (choose) {
	case 0:
		exit(0);

	case 1:
		cout << "NHAP DANH SACH NHAN VIEN\n\n";
		NhapDSNV(nv, n);
		break;

	case 2:
		cout << "XUAT DANH SACH NHAN VIEN";
		XuatDSNV(nv, n);
		break;

	case 3:
		cout << "THUC LANH CAC NHAN VIEN\n\n";
		for (int i = 0; i < n; ++i)
			cout << " - Thuc lanh nhan vien " << nv[i].HoTen << " = " << ThucLanh(nv[i]) << "\n";
		break;

	case 4:
		cout << "DANH SACH NHAN VIEN CO LUONG CO BAN THAP NHAT\n\n";
		XuatLCB_Min(nv, n);
		break;

	case 5:
		cout << "SO LUONG NHAN VIEN CO MUC THUONG >= 1200000: " << DemNhanVien(nv, n);
		break;

	case 6:
		cout << "DANH SACH NHAN VIEN THEO PHONG BAN\n";
		NVTheoPB(nv, n);
		break;
	}

	//Sau khi thực hiện yêu cầu thì yêu cầu có về trang chủ hay không
	//Nếu không thì xoá mảng động và thoát
	cout << "\n\nVe trang chu (0/1): ";
	cin >> choose;
	if (choose) {
		system("cls");
		BangChon(nv, n);
	}
	else {
		delete[]nv;
		exit(0);
	}
}

int main() {
	NhanVien *nv;
	int n;

	BangChon(nv, n);
	system("pause");
}