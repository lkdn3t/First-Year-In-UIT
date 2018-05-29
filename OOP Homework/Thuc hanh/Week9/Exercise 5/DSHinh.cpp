#include "DSHinh.h"
#define inf 100000

float min(float a, float b, float c, float d) {
	return min(min(a, b), min(c, d));
}

float max(float a, float b, float c, float d) {
	return max(max(a, b), max(c, d));
}

void DSHinh::NhapDS(const char * FileName) {
	ifstream ifile;
	ifile.open(FileName);

	ifile >> SoLuong;
	char LoaiHinh;

	for (int i = 0; i < SoLuong; i++) {
		Hinh* hinh;
		ifile >> LoaiHinh;

		switch (LoaiHinh) {
		case 'G': { //tam giác
			hinh = new TamGiac;
			hinh->Nhap(ifile);
			break;
		}

		case 'C': { //chữ nhật
			hinh = new ChuNhat;
			hinh->Nhap(ifile);
			break;
		}

		case 'V': { //vuông
			hinh = new Vuong;
			hinh->Nhap(ifile);
			break;
		}

		case 'T': { //tròn
			hinh = new Tron;
			hinh->Nhap(ifile);
			break;
		}
		}
		DS_Hinh.push_back(hinh);
	}
	ifile.close();
}

void DSHinh::XuatKQ(const char* FileName) {
	float xTraiTren = inf, xPhaiDuoi = -inf;
	float yTraiTren = -inf, yPhaiDuoi = inf;

	for (int i = 0; i < SoLuong; i++) {
		char LoaiHinh = DS_Hinh[i]->getLoai();
		switch (LoaiHinh) {
		case 'G': { //tam giác
			TamGiac *tg = (TamGiac*)DS_Hinh[i];
			xTraiTren = min(xTraiTren, tg->getAx(), tg->getBx(), tg->getCx());
			yTraiTren = max(yTraiTren, tg->getAy(), tg->getBy(), tg->getCy());
			xPhaiDuoi = max(xPhaiDuoi, tg->getAx(), tg->getBx(), tg->getCx());
			yPhaiDuoi = min(yPhaiDuoi, tg->getAy(), tg->getBy(), tg->getCy());
			delete tg;
			break;
		}


		case 'C': { //chữ nhật
			ChuNhat *cn = (ChuNhat*)DS_Hinh[i];
			xTraiTren = min(xTraiTren, cn->getTraiTren().x);
			yTraiTren = max(yTraiTren, cn->getTraiTren().y);
			xPhaiDuoi = max(xPhaiDuoi, cn->getTraiTren().x + cn->getDai());
			yPhaiDuoi = min(yPhaiDuoi, cn->getTraiTren().y - cn->getRong());
			delete cn;
			break;
		}

		case 'V': { //vuông
			Vuong *vg = (Vuong*)DS_Hinh[i];
			xTraiTren = min(xTraiTren, vg->getTraiTren().x);
			yTraiTren = max(yTraiTren, vg->getTraiTren().y);
			xPhaiDuoi = max(xPhaiDuoi, vg->getTraiTren().x + vg->getDai());
			yPhaiDuoi = min(yPhaiDuoi, vg->getTraiTren().y - vg->getRong());
			delete vg;
			break;
		}

		case 'T': { //tròn
			Tron *tr = (Tron*)DS_Hinh[i];
			xTraiTren = min(xTraiTren, tr->getTam().x - tr->getBanKinh());
			yTraiTren = max(yTraiTren, tr->getTam().y + tr->getBanKinh());
			xPhaiDuoi = max(xPhaiDuoi, tr->getTam().x + tr->getBanKinh());
			yPhaiDuoi = min(yPhaiDuoi, tr->getTam().y - tr->getBanKinh());
			delete tr;
			break;
		}
		}
	}

	ofstream ofile;
	ofile.open(FileName);
	ofile << xTraiTren << " " << yTraiTren << " " << xPhaiDuoi - xTraiTren << " " << yPhaiDuoi - yTraiTren;
	ofile.close();
}