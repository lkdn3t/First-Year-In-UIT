#include "GVTG.h"

GVTG::GVTG(string Ten, string Email, string DiaChi, string DienThoai, string CoQuan, int SoGioDay) {
	this->Ten = Ten;
	this->Email = Email;
	this->DiaChi = DiaChi;
	this->DienThoai = DienThoai;
	this->CoQuan = CoQuan;
	this->SoGioDay = SoGioDay;
}

string GVTG::getTen() const {
	return Ten;
}

string GVTG::getEmail() const {
	return Email;
}

string GVTG::getDiaChi() const {
	return DiaChi;
}

string GVTG::getDienThoai() const {
	return DienThoai;
}

string GVTG::getCoQuan() const {
	return CoQuan;
}

int GVTG::getSoGioDay() const {
	return SoGioDay;
}

long GVTG::getTongLuong() const {
	return TongLuong;
}

void GVTG::setTen(string Ten) {
	this->Ten = Ten;
}

void GVTG::setEmail(string Email) {
	this->Email = Email;
}

void GVTG::setDiaChi(string DiaChi) {
	this->DiaChi = DiaChi;
}

void GVTG::setDienThoai(string DienThoai) {
	this->DienThoai = DienThoai;
}

void GVTG::setCoQuan(string CoQuan) {
	this->CoQuan = CoQuan;
}

void GVTG::setSoGioDay(int SoGioDay) {
	this->SoGioDay = SoGioDay;
}

void GVTG::setTongLuong(long TongLuong) {
	this->TongLuong = TongLuong;
}

void GVTG::TinhTongLuong() {
	TongLuong = SoGioDay * LuongGio;
}

void GVTG::Nhap() {
	cout << "Nhap ten: "       ; getline(cin, Ten);
	cout << "Nhap email: "     ; getline(cin, Email);
	cout << "Nhap dia chi: "   ; getline(cin, DiaChi);
	cout << "Nhap dien thoai: "; getline(cin, DienThoai);
	cout << "Nhap co quan: "   ; getline(cin, CoQuan);
	cout << "Nhap so gio day: "; cin >> SoGioDay;
	TinhTongLuong();
}

void GVTG::Xuat() const {
	cout << "Ten: "        << Ten << endl;
	cout << "Email: "      << Email << endl;
	cout << "Dia chi: "    << DiaChi << endl;
	cout << "Dien thoai: " << DienThoai << endl;
	cout << "Co quan: "    << CoQuan << endl;
	cout << "So gio day: " << SoGioDay << endl;
}