#include "Tron.h"

void Tron::Nhap(ifstream& ifile) {
	ifile >> Tam.x >> Tam.y;
	ifile >> BanKinh;
}

char Tron::getLoai() {
	return 'T';
}

Diem Tron::getTam() {
	return Tam;
}

float Tron::getBanKinh() {
	return BanKinh;
}
