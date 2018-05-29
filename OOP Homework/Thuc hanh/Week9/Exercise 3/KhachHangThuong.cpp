#include "KhachHangThuong.h"

long KhachHangThuong::SoTienPhaiTra() {
	return SoLuongHang * DonGiaHang * (1 + ThueVAT);
}