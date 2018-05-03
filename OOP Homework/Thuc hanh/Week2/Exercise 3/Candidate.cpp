#include "Candidate.h"
using namespace std;

//Định các hàm get
string Candidate::getName()       const       { return Name;       }
string Candidate::getID()         const       { return ID;         }
Date   Candidate::getBirth()      const       { return Birth;      }
float  Candidate::getMathScore()  const       { return MathScore;  }
float  Candidate::getLiterScore() const       { return LiterScore; }
float  Candidate::getEngScore()   const       { return EngScore;   }

//Định các hàm set
void Candidate::setName       (string Name)   { this->Name       = Name;    }
void Candidate::setID         (string ID)     { this->ID         = ID;      }
void Candidate::setMathScore  (float  MScore) { this->MathScore  = MScore;  }
void Candidate::setLiterScore (float  LScore) { this->LiterScore = LScore;  }
void Candidate::setEngScore   (float  EScore) { this->EngScore   = EScore;  }
void Candidate::setBirth(int d, int m, int y) {
    this->Birth.day   = d;
    this->Birth.month = m;
    this->Birth.year  = y;
}

//Nhập thông tin của thí sinh:
//Gồm: tên, mã, ngày tháng năm sinh, điểm toán, văn, anh
void Candidate::inputCandidate() {
    cin.ignore();
    cout << "  - Nhap ho ten: "    ;  getline(cin, Name);
    cout << "  - Nhap ma so: "     ;  getline(cin, ID);
    cout << "  - Nhap ngay sinh\n" ;
    cout << "      *Nhap ngay: "   ;  cin >> Birth.day;
    cout << "      *Nhap thang: "  ;  cin >> Birth.month;
    cout << "      *Nhap nam: "    ;  cin >> Birth.year;
    cout << "  - Nhap diem toan: " ;  cin >> MathScore;
    cout << "  - Nhap diem van: "  ;  cin >> LiterScore;
    cout << "  - Nhap diem anh: "  ;  cin >> EngScore;
}

//Xuất thông tin của thí sinh
void Candidate::putCandidate() {
    cout << "  - Ho ten: "        << Name;
    cout << "\n  - Ma so: "       << ID;
    cout << "\n  - Ngay sinh: "   << Birth.day << "/" << Birth.month << "/" << Birth.year;
    cout << "\n  - Diem toan: "   << MathScore;
    cout << "\n  - Diem van: "    << LiterScore;
    cout << "\n  - Diem anh: "    << EngScore << "\n"; 
}