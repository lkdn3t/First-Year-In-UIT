//Các hàm nhập xuất ma trận
void NhapMaTran(int a[][3], int n);
void XuatMaTran(int a[][3], int n);
void MaTranCheo(int a[][3], int n);

//Các hàm thao tác với ma trận 2x2
int SoTriRiengMT2(int a, int b, int c);
void TimTriRiengMT2(int a, int b, int c);
void VectoMT2(float a, int b, int c, float d);

//Các hàm thao tác với ma trận 3x3
int SoTriRiengMT3(int a, int b, int c, int d);
void TimTriRiengMT3(int a, int b, int c, int d);
void TriRiengMT3();

//Các hàm dành cho bảng chọn
void BangChon();
void ChonLai();

//Các hàm kiểm tra tính hợp lệ của ma trận
bool KTKhong(int a[][3], int n);
bool KTCheo(int a[][3], int n);
bool KTDoiXung(int a[][3], int n);

//Các hàm áp dụng cho yêu cầu 1 và 3: chéo hoá ma trận 2x2
void CheoHoaMT2();
void Xuat_TriRiengMT2(int a[][3], int n);
void Xuat_VectoMT2(int a[][3], int n);
void Xuat_MT2Cheo(int a[][3], int n);

//Các hàm áp dụng cho yêu cầu 2: Tìm trị riêng của ma trận 3x3
void Xuat_TriRiengMT3(int a[][3], int n);

//Các hàm áp dụng cho yêu cầu 3: Chéo hoá trực giao ma trận 2x2
void CheoHoaTG();
void Xuat_CSTCMT2(int a[][3], int n);