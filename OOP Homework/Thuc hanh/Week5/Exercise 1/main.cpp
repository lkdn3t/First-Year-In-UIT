#include "String.h"

using namespace std;

int main(int argc, char *argv[]) {
    //Nhập hai chuỗi
    String str1, str2;
    int len1, len2;
    
    cout << "...NHAP HAI CHUOI...\n";
    cout << "Nhap do dai chuoi thu nhat: ";
    cin >> len1; cin.ignore();
    cout << "Nhap chuoi thu nhat: ";
    str1.getString(len1);
    
    cout << "\nNhap do dai chuoi thu hai: ";
    cin >> len2; cin.ignore();
    cout << "Nhap chuoi thu hai:  ";
    str2.getString(len2);

    //Xuất hai chuỗi
    cout << "\n...XUAT HAI CHUOI...\n";
    cout << "Chuoi thu nhat: "; str1.putString();
    cout << "Chuoi thu hai:  "; str2.putString();

    //Xuất các chuỗi phép toán
    cout << "\n...CAC CHUOI PHEP TOAN...\n";
    cout << "Chuoi tong: ";          str1.Add(str2).putString();
    cout << "Chuoi dao thu nhat: ";  str1.Reverse().putString();
    cout << "Chuoi dao thu hai: " ;  str2.Reverse().putString();

    system("pause");
    return 1;
}