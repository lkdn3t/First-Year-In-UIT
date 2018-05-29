	#include "ChuNhat.h"

void ChuNhat::Nhap(ifstream & ifile) {
	ifile >> TraiTren.x >> TraiTren.y;
	ifile >> Dai >> Rong;
}

char ChuNhat::getLoai() {
	return 'C';
}

Diem ChuNhat::getTraiTren() {
	return TraiTren;
}

float ChuNhat::getDai() {
	return Dai;
}

float ChuNhat::getRong() {
	return Rong;
}