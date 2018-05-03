#include <iostream>
#include <string>

using namespace std;

class GVTG {
private:
	string Ten;
	string Email;
	string DiaChi;
	string DienThoai;
	string CoQuan;
	int SoGioDay;
	const long LuongGio = 200000;
	long TongLuong;

public:
	GVTG() {};
	GVTG(string Ten, string Email, string DiaChi, string DienThoai, string CoQuan, int SoGioDay);
	
public:
	string getTen() const;
	string getEmail() const;
	string getDiaChi() const;
	string getDienThoai() const;
	string getCoQuan() const;
	int getSoGioDay() const;
	long getTongLuong() const;

public:
	void setTen(string Ten);
	void setEmail(string Email);
	void setDiaChi(string DiaChi);
	void setDienThoai(string DienThoai);
	void setCoQuan(string CoQuan);
	void setSoGioDay(int SoGioDay);
	void setTongLuong(long TongLuong);

public:
	void TinhTongLuong();
	void Nhap();
	void Xuat() const;
};	