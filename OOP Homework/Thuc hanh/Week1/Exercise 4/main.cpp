#include "Date.h"
using namespace std;

int main(int argc, char *argv[]) {
    //Nhập vào ngày và xuất ra
    Date today;
    cout << "...Tim ngay ke tiep...\n";
    today.inputDate();
    cout << "\nNgay da nhap: ";
    today.putDate();

    //Xuất ra ngày kế tiếp
    Date nday = today.NextDay();
    cout << "Ngay ke tiep: ";
    nday.putDate();

    system("pause");
    return 1;
}