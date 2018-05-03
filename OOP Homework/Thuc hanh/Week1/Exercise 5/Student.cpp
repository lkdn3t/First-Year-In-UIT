#include "Student.h"
using namespace std;

//Tạo constructor cho sinh viên
Student::Student(string Name, float MScore, float LScore) {
    this->Name       = Name;
    this->MathScore  = MScore;
    this->LiterScore = LScore;
}

//Tính điểm trung bình của sinh viên
void Student::computeAverage() {
    AverageScore = (MathScore + LiterScore) / 2;
}

//Nhập các thông tin của sinh viên
void Student::inputStudent() {
    cout << "\tNhap ho ten: "   ; getline(cin, Name);
    cout << "\tNhap diem toan: "; cin >> MathScore;
    cout << "\tNhap diem van: " ; cin >> LiterScore;  
}

//Xuất thông tin của sinh viên + điểm trung bình
void Student::putStudent() {
    computeAverage();
    cout << "\tHo ten: "       << Name;
    cout << "\n\tDiem toan: "  << MathScore;
    cout << "\n\tDiem van: "   << LiterScore;
    cout << "\n\tTrung binh: " << AverageScore << "\n";
}