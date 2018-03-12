#include "NgayThang.h"

int SoNgayTrongThang(int thang, int nam) {
	if (thang < 0 || thang > 12 || nam < 0)
		return -1;
	switch (thang) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		bool ktNhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
		return ktNhuan ? 29 : 28;
	}
}