#include "TamGiac.h"

void TamGiac::Nhap(ifstream & ifile) {
	ifile >> A.x >> A.y;
	ifile >> B.x >> B.y;
	ifile >> C.x >> C.y;
}

float TamGiac::getAx() {
	return A.x;
}

float TamGiac::getAy() {
	return A.y;
}

float TamGiac::getBx() {
	return B.x;
}

float TamGiac::getBy() {
	return B.y;
}

float TamGiac::getCx() {
	return C.x;
}

float TamGiac::getCy() {
	return C.y;
}

char TamGiac::getLoai() {
	return 'G';
}
