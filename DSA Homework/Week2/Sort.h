#include <iostream>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

//Tạo struct phân số gồm tử và mẫu
struct PhanSo {
	int tu;
	int mau;
};

int SoSanhPS(PhanSo p1, PhanSo p2);
void NhapMangPS(const char*, PhanSo*&, int&);
void XuatMangPS(const char*, PhanSo*, int);
void BubbleSort(PhanSo *ps, int n);

void NhapMangChuoi(const char*, string*&, int&);
void XuatMangChuoi(const char*, string*, int);
void QuickSort(string*, int, int);

void NhapMangInt(const char*, int*&, int&);
void XuatMangInt(const char*, int*, int);
void Merge(int*, int, int, int);
void MergeSort(int*, int, int);