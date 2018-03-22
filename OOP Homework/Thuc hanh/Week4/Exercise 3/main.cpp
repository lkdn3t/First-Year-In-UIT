#include "Date.h"
using namespace std;

int main(int argc, char *argv[]) {
    //Nhập vào hai ngày
    Date date1, date2;
    cout << "...Nhap ngay thu nhat...\n"  ; date1.getDate();
    cout << "\n...Nhap ngay thu hai...\n" ; date2.getDate();

    //Tìm độ lệch của hai ngày
    cout << "\n-> Hai ngay cach nhau " << date1.DiffDays(date2) << " ngay\n\n";
    system("pause");
    return 1;
}