#pragma once
#include "ChuNhat.h"
#include "Vuong.h"
#include "Tron.h"
#include "TamGiac.h"
#include <vector>
#include <algorithm>

class DSHinh {
public:
	void NhapDS(const char* FileName);
	void XuatKQ(const char* FileName);

private:
	vector<Hinh*> DS_Hinh;
	int SoLuong;
};