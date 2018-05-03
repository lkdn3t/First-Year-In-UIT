#include "Triangle.h"
using namespace std;

int main() {
    //Khởi tạo và nhập các định của ABC
    cout << "...Nhap toa do cac dinh cua tam giac ABC...\n";
    Triangle triangle;
    triangle.getTriangle();

    //Xuất tam giác ABC
    cout << "\n...Toa do cac dinh cua tam giac ABC...\n";
    triangle.putTriangle();
    
    //Mở bảng chọn và thực hiện
    while (true) triangle.chooseBoard();
    
    //Thực hiện đến khi chọn lệnh kết thúc thì dừng
    system("pause");
    return 1;
}