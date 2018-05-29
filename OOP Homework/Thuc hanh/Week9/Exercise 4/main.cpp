#include "DanhSachPhong.h"

int main() {
	const char *iFileName = "SOFITEL.INP";
	const char *oFileName = "SOFITEL.OUT";

	DanhSachPhong *DSPhongKS = new DanhSachPhong;
	DSPhongKS->LayDanhSach(iFileName);
	DSPhongKS->XuatDanhSach(oFileName);

	return 0;
}