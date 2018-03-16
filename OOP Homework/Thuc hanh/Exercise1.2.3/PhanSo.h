#include <iostream>
using namespace std;

class PhanSo {
private:
    int  TuSo;
    int  MauSo;
    void RutGon();

public:
    PhanSo(int tu = 0, int mau = 1);
    void Nhap();
    void Xuat();
    bool SoSanh(PhanSo);
    
public:
    int  getTuSo();
    int  getMauSo();
    void setTuSo(int);
    void setMauSo(int);

public:
    PhanSo Cong(PhanSo);
    PhanSo Tru(PhanSo);
    PhanSo Nhan(PhanSo);
    PhanSo Chia(PhanSo);
};