#include "GVCH.h"

GVCH::GVCH(string Ten, string Email, string DiaChi, string DienThoai, long LuongThoaThuan, int SoGioDay) {
	this->Ten = Ten;
	this->Email = Email;
	this->DiaChi = DiaChi;
	this->DienThoai = DienThoai;
	this->LuongThoaThuan = LuongThoaThuan;
	this->SoGioDay = SoGioDay;
}

string GVCH::getTen() const {
	return Ten;
}

string GVCH::getEmail() const {
	return Email;
}

string GVCH::getDiaChi() const {
	return DiaChi;
}

string GVCH::getDienThoai() const {
	return DienThoai;
}

long GVCH::getLuongThoaThuan() const {
	return LuongThoaThuan;
}

int GVCH::getSoGioDay() const {
	return SoGioDay;
}

int GVCH::getSoGioQD() const {
	return SoGioQD;
}

long GVCH::getTongLuong() const {
	return TongLuong;
}

void GVCH::setTen(string Ten) {
	this->Ten = Ten;
}

void GVCH::setEmail(string Email) {
	this->Email = Email;
}

void GVCH::setDiaChi(string DiaChi) {
	this->DiaChi = DiaChi;
}

void GVCH::setLuongThoaThuan(long LuongThoaThuan) {
	this->LuongThoaThuan = LuongThoaThuan;
}

void GVCH::setDienThoai(string DienThoai) {
	this->DienThoai = DienThoai;
}

void GVCH::setSoGioDay(int SoGioDay) {
	this->SoGioDay = SoGioDay;
}

void GVCH::setTongLuong(long TongLuong) {
	this->TongLuong = TongLuong;
}

void GVCH::TinhTongLuong() {
	if (SoGioDay > SoGioQD) {
		long LuongThuong;
		cout << "Nhap luong thuong: ";
		cin >> LuongThuong;
		TongLuong = LuongThoaThuan + LuongThuong;
	}
	else TongLuong = LuongThoaThuan;
}

void GVCH::Nhap() {
	cout << "Nhap ten: "             ; getline(cin, Ten);
	cout << "Nhap email: "           ; getline(cin, Email);
	cout << "Nhap dia chi: "         ; getline(cin, DiaChi);
	cout << "Nhap dien thoai: "      ; getline(cin, DienThoai);
	cout << "Nhap so gio day: "      ; cin >> SoGioDay;
	cout << "Nhap luong thoa thuan: "; cin >> LuongThoaThuan;
	TinhTongLuong();
}

void GVCH::Xuat() const {
	cout << "Ten: "              << Ten << endl;
	cout << "Email: "            << Email << endl;
	cout << "Dia chi: "          << DiaChi << endl;
	cout << "Dien thoai: "       << DienThoai << endl;
	cout << "So gio day: "       << SoGioDay << endl;
	cout << "Luong thoa thuan: " << LuongThoaThuan << endl;
}