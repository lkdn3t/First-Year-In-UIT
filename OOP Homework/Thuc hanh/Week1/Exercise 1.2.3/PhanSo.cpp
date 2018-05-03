#include "PhanSo.h"
using namespace std;

//Constructor cho phân số
PhanSo::PhanSo(int tu, int mau) {
    TuSo = tu; MauSo = mau;
}

//Các hàm get, set cho phân số
int  PhanSo::getTuSo()         { return TuSo;  }
int  PhanSo::getMauSo()        { return MauSo; }
void PhanSo::setTuSo(int tu)   { TuSo  = tu;   }
void PhanSo::setMauSo(int mau) { MauSo = mau;  }

//Nhập phân số (mẫu != 0)
void PhanSo::Nhap() {
    cout << "\tNhap tu so: " ; cin >> TuSo;
    cout << "\tNhap mau so: "; cin >> MauSo;

    while(!MauSo) {
        cout << "\tNhap lai mau so: ";
        cin >> MauSo;
    }
}

//Xuất phân số (nếu mẫu = 1 hoặc tử = 0 thì không xuất mẫu)
void PhanSo::Xuat(){
    cout << TuSo;
    if(MauSo != 1 && TuSo)
        cout << "/" << MauSo << "\n";
}

//So sánh hai phân số
//1: lớn, 0: bằng, -1: nhỏ
bool PhanSo::SoSanh(PhanSo ps) {
    float g1 = (float)TuSo / MauSo;
    float g2 = (float)ps.TuSo / ps.MauSo;
    return g1 > g2 ? 1 : g1 == g2 ? 0 : -1;
}

//Rút gọn phân số
int UCLN(int a, int b) { return b == 0 ? a : UCLN(b, a % b); }
void PhanSo::RutGon() {
    int uc = UCLN(TuSo, MauSo);
    TuSo /= uc; MauSo /= uc;
}

//Cộng hai phân số
PhanSo PhanSo::Cong(PhanSo p) {
    PhanSo Tong = PhanSo(TuSo * p.MauSo + MauSo * p.TuSo, MauSo * p.MauSo);
    Tong.RutGon();
    return Tong;
}

//Trừ hai phân số
PhanSo PhanSo::Tru(PhanSo p) {
    PhanSo Hieu = PhanSo(TuSo * p.MauSo - MauSo * p.TuSo, MauSo * p.MauSo);
    Hieu.RutGon();
    return Hieu;
}

//Nhân hai phân số
PhanSo PhanSo::Nhan(PhanSo p) {
    PhanSo Tich = PhanSo(TuSo * p.TuSo, MauSo * p.MauSo);
    Tich.RutGon();
    return Tich;
}

//Chia hai phân số
PhanSo PhanSo::Chia(PhanSo p) {
    PhanSo Thuong = PhanSo(TuSo * p.MauSo, MauSo * p.TuSo);
    Thuong.RutGon();
    return Thuong;
}