#include "PhanSo.h"
using namespace std;

int main(int argc, char *argv[]) {
    //Nhập hai phân số
    PhanSo ps1, ps2;
    cout << "Nhap phan so 1:\n";     ps1.Nhap();
    cout << "\nNhap phan so 2:\n";   ps2.Nhap();

    //Xuất hai phân số
    cout << "\nPhan so thu nhat: ";  ps1.Xuat();
    cout << "Phan so thu hai: ";     ps2.Xuat();

    //Tính tổng, hiểu tích thương hai phân số
    cout << "\nTong hai phan so = ";  ps1.Cong(ps2).Xuat();
    cout << "Hieu hai phan so = ";    ps1.Tru(ps2).Xuat();
    cout << "Tich hai phan so = ";    ps1.Nhan(ps2).Xuat();
    if (!ps2.getTuSo()) cout << "Khong the chia cho 0!\n";
    else cout << "Thuong hai phan so = "; ps1.Chia(ps2).Xuat();

    system("pause");
    return 0;
}