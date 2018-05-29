#include "KhachHangDacBiet.h"

long KhachHangDacBiet::SoTienPhaiTra() {
	return SoLuongHang * DonGiaHang * (0.5 + ThueVAT);
}
