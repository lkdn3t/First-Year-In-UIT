#include <iostream>
#include <string>

using namespace std;

class GVCH {
private:
	string Ten;
	string Email;
	string DiaChi;
	string DienThoai;
	int SoGioDay;
	long LuongThoaThuan;
	long TongLuong;
	const int SoGioQD = 40;

public:
	GVCH() {};
	GVCH(string Ten, string Email, string DiaChi, string DienThoai, long LuongThoaThuan, int SoGioDay);

public:
	string getTen() const;
	string getEmail() const;
	string getDiaChi() const;
	string getDienThoai() const;
	long getLuongThoaThuan() const;
	int getSoGioDay() const;
	int getSoGioQD() const;
	long getTongLuong() const;

public:
	void setTen(string Ten);
	void setEmail(string Email);
	void setDiaChi(string DiaChi);
	void setLuongThoaThuan(long LuongThoaThuan);
	void setDienThoai(string DienThoai);
	void setSoGioDay(int SoGioDay);
	void setTongLuong(long TongLuong);

public:
	void TinhTongLuong();
	void Nhap();
	void Xuat() const;
};