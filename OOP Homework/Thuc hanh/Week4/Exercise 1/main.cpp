#include "TimeSpan.h"
using namespace std;

int main(int argc, char *argv[]) {
    //Khởi tạo và nhập thời gian
    TimeSpan time1, time2;
    cout << "...Nhap thoi gian t1...\n"; time1.getTime();
    cout << "...Nhap thoi gian t2...\n"; time2.getTime();

    //Xuất thời gian đã nhập
    cout << "...Thoi gian da nhap...\n";
    cout << "Thoi gian t1: "; time1.putTime();
    cout << "Thoi gian t2: "; time2.putTime();

    //Xuất tổng và hiệu hai thời gian
    cout << "\n...Tong va hieu hai thoi gian...\n";
    cout << "Tong  t1 + t2  = "  ; time1.Add(time2).putTime();
    cout << "Hieu |t1 - t2| = "; time1.Subtract(time2).putTime();

    system("pause");
    return 1;
}