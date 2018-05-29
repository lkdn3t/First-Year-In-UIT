#include "DanhSachPhong.h"

long (DanhSachPhong::*pTongDoanhThuPhong)(string Loai, int SoLuong) = &DanhSachPhong::TongDoanhThuPhong;

DanhSachPhong::~DanhSachPhong() {
	for (int i = 0; i < SoLuongPhong; i++)
		delete PhongKS[i];
	delete[] PhongKS;
}

void DanhSachPhong::LayDanhSach(const char * FileName) {
	ifstream ifile;
	ifile.open(FileName);

	ifile >> SoPhongDeluxe >> SoPhongPremium >> SoPhongBusiness;
	SoLuongPhong = SoPhongDeluxe + SoPhongPremium + SoPhongBusiness;
	PhongKS = new PhongKhachSan*[SoLuongPhong];

	int vt = 0;
	for (int i = 0; i < SoPhongDeluxe; i++, vt++) {
		ifile.ignore();
		PhongKS[vt] = new PhongDeluxe;
		PhongKS[vt]->LayThongTin(ifile);
	}

	for (int i = 0; i < SoPhongPremium; i++, vt++) {
		ifile.ignore();
		PhongKS[vt] = new PhongPremium;
		PhongKS[vt]->LayThongTin(ifile);
	}

	for (int i = 0; i < SoPhongBusiness; i++, vt++) {
		ifile.ignore();
		PhongKS[vt] = new PhongBusiness;
		PhongKS[vt]->LayThongTin(ifile);
	}
	ifile.close();
}

void DanhSachPhong::XuatDanhSach(const char * FileName) {
	ofstream ofile;
	ofile.open(FileName);

	ofile << SoPhongDeluxe << " " << SoPhongPremium << " " << SoPhongBusiness << endl;
	ofile << TongDoanhThuPhong("Deluxe", SoPhongDeluxe) << endl;
	ofile << (*this.*pTongDoanhThuPhong)("Deluxe", SoPhongDeluxe) << endl;
	ofile << (*this.*pTongDoanhThuPhong)("Premium", SoPhongPremium) << endl;
	ofile << (*this.*pTongDoanhThuPhong)("Business", SoPhongBusiness) << endl;

	vector<string> DSPhongVT = DanhSachPhongVuotTroi();
	ofile << DSPhongVT.size() << endl;
	for (int i = 0; i < DSPhongVT.size(); i++) {
		ofile << DSPhongVT[i] << endl;
	}
	ofile.close();
}

long DanhSachPhong::TongDoanhThuPhong(string Loai, int SoLuong) {
	long TongDoanhThu = 0;
	int vt;

	if (Loai == "Deluxe")
		vt = 0;
	else if (Loai == "Premium")
		vt = SoPhongDeluxe;
	else if (Loai == "Business")
		vt = SoPhongDeluxe + SoPhongPremium;

	for (int i = 0; i < SoLuong; i++, vt++)
		TongDoanhThu += PhongKS[vt]->DoanhThuPhong();
	return TongDoanhThu;
}

vector<string> DanhSachPhong::DanhSachPhongVuotTroi() {
	vector<string> DS_MaPhongVuotTroi;
	int vt = 1;

	for (int i = 1; i < SoPhongDeluxe; i++, vt++) {
		if (PhongKS[vt]->DoanhThuPhong() >= 1.25f * PhongKS[vt - 1]->DoanhThuPhong())
			DS_MaPhongVuotTroi.push_back(PhongKS[vt]->getMaPhong());
	}

	vt++;
	for (int i = 1; i < SoPhongPremium; i++, vt++) {
		if (PhongKS[vt]->DoanhThuPhong() >= 1.25f * PhongKS[vt - 1]->DoanhThuPhong())
			DS_MaPhongVuotTroi.push_back(PhongKS[vt]->getMaPhong());
	}

	vt++;
	for (int i = 1; i < SoPhongBusiness; i++, vt++) {
		if (PhongKS[vt]->DoanhThuPhong() >= 1.25f * PhongKS[vt - 1]->DoanhThuPhong())
			DS_MaPhongVuotTroi.push_back(PhongKS[vt]->getMaPhong());
	}
	return DS_MaPhongVuotTroi;
}