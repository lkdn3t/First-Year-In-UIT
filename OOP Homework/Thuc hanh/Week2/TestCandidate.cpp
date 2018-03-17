#include "TestCandidate.h"
#define PutLine cout << "\n--------------------------------------------------------"
using namespace std;

//Constructor cho danh sách thí sinh
TestCandidate::TestCandidate(int NumCdd, Candidate *ListCdd) {
    this->NumCdd  = NumCdd;
    this->ListCdd = ListCdd;
}

//Destructor cho danh sách thí sinh
TestCandidate::~TestCandidate() {
    delete[]ListCdd;
}

//Nhập danh sách thí sinh
void TestCandidate::inputListCdd() {
    cout << "Nhap so luong thi sinh: "; cin >> NumCdd;
    ListCdd = new Candidate[NumCdd];
    
    PutLine;
    cout << "\n[NHAP DANH SACH CAC THI SINH]\n";
    for (int i = 0; i < NumCdd; ++i) {
        cout << "\n...Nhap thong tin thi sinh thu " << i + 1 << "...\n";
        ListCdd[i].inputCandidate();
    }
}

//Xuất danh sách thí sinh
void TestCandidate::putListCdd() {
    PutLine;
    cout << "\n[DANH SACH THI SINH NHAP VAO]\n";
    for (int i = 0; i < NumCdd; ++i) {
        cout << "\n...Thong tin thi sinh thu " << i + 1 << "...\n";
        ListCdd[i].putCandidate();
    }
}

//Xuất danh sách thí sinh có tổng điểm lớn hơn 15
void TestCandidate::putListPassCdd() {
    PutLine;
    cout << "\n[DANH SACH THI SINH CO TONG DIEM LON HON 15]\n";
    int count = 0;
    for (int i = 0; i < NumCdd; ++i) {
        float SumScore = ListCdd[i].getMathScore() + ListCdd[i].getLiterScore() + ListCdd[i].getLiterScore();
        if (SumScore > 15) {
            cout << "\n...Thi sinh thu " << ++count << "...\n";
            ListCdd[i].putCandidate();
        }
    }
}