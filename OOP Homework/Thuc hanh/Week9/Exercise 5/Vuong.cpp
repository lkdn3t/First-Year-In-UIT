#include "Vuong.h"

void Vuong::Nhap(ifstream & ifile) {
	ifile >> TraiTren.x >> TraiTren.y;
	ifile >> Dai;
	Rong = Dai;
}

char Vuong::getLoai() {
	return 'V';
}
