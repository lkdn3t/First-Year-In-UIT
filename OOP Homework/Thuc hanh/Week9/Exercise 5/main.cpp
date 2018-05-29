#include "DSHinh.h"

int main() {
	const char *iFileName = "INPUT.DAT";
	const char *oFileName = "OUTPUT.DAT";

	DSHinh *ds_hinh = new DSHinh;
	ds_hinh->NhapDS(iFileName);
	ds_hinh->XuatKQ(oFileName);
	delete ds_hinh;
	return 0;
}