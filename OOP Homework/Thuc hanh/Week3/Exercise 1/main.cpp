#include "Point2D.h"
using namespace std;

int main(int argc, char *argv[]) {
    //Nhập hai điểm A, B
    Point2D A, B;
    cout << "Nhap diem A:\n"; A.inputPoint();
    cout << "Nhap diem B:\n"; B.inputPoint();

    //Xuất hai điểm A, B
    cout << "\n...Hai diem da nhap...\n";
    cout << "  - Diem A"; A.putPoint();
    cout << "  - Diem B"; B.putPoint();

    //Tịnh tiến hai điểm A
    float dx, dy;
    cout << "\n...Tinh tien diem A...\n";
    cout << "  - Nhap hoanh do: "; cin >> dx;
    cout << "  - Nhap tung do: " ; cin >> dy;
    cout << "  - Diem A sau khi tinh tien: A";
    A.movePoint(dx, dy); A.putPoint();

    system("pause");
    return 1;
}