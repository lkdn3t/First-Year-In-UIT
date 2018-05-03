#include "Triangle.h"
#define PutLine cout << "\n-------------------------------------------\n"
using namespace std;

//Định constructor cho tam giác
Triangle::Triangle(float Ax, float Ay, float Bx, float By, float Cx, float Cy) {
    A.setX(Ax); A.setY(Ay);
    B.setX(Bx); B.setY(By);
    C.setX(Cx); C.setY(Cy);
}   

Triangle::Triangle(Point2D A, Point2D B, Point2D C) {
    this->A = A; this->B = B; this->C = C;
}

//Kiểm tra ba điểm nhập vào có tạo thành tam giác
//bằng điều kiện cùng phương của vector (xem như điểm)
bool Triangle::isTriangle() {
    Point2D v1(A.getX() - B.getX(), A.getY() - B.getY());
    Point2D v2(A.getX() - C.getX(), A.getY() - C.getY());
    
    if (A.isEqual(B) || B.isEqual(C) || C.isEqual(A))
        return false;
    if (v1.getY() == v2.getY() && !v1.getY())
        return false;
    if (!v1.getY() || !v2.getY()) 
        return true;
    return (v1.getX() / v1.getY() != v2.getX() / v2.getY());
}

//Nhập các điểm cho tam giác
void Triangle::getTriangle() {
    cout << "Nhap dinh A:\n"; A.inputPoint();
    cout << "Nhap dinh B:\n"; B.inputPoint();
    cout << "Nhap dinh C:\n"; C.inputPoint();

    if (!isTriangle()) {
        cout << " Ba dinh khong tao thanh tam giac!";
        cout << "\n Vui long nhap lai ba dinh\n";
        getTriangle();
    }
}

//Xuất các điểm cho tam giác
void Triangle::putTriangle() {
    cout << "   - Dinh A "; A.putPoint();
    cout << "   - Dinh B "; B.putPoint();
    cout << "   - Dinh C "; C.putPoint();
}

//Tịnh tiến tam giác
void Triangle::moveTriangle(float dx, float dy) {
    A.movePoint(dx, dy);
    B.movePoint(dx, dy);
    C.movePoint(dx, dy);
}

//Phóng to tam giác (với hệ số và tâm cố định để phóng)
//Có thể tạo thêm hàm enlargePoint ở Point2D và gọi 3 hàm đó ở đây
void Triangle::enlargeTriangle(float scale, Point2D P) {
    A.movePoint(A.diffX(P) * (scale - 1), A.diffY(P) * (scale - 1));
    B.movePoint(B.diffX(P) * (scale - 1), B.diffY(P) * (scale - 1));
    C.movePoint(C.diffX(P) * (scale - 1), C.diffY(P) * (scale - 1));
}

//Thu nhỏ tam giác (với hệ số và tâm cố định để phóng)
//Bản chất là phóng to tam giác nhưng hệ số scale = 1/scale
void Triangle::shrinkTriangle(float scale, Point2D P) {
    enlargeTriangle(1 / scale, P);
}

//Xoay tam giác (xoay các đỉnh theo góc của 1 tâm cố định)
//Bản chất là xoay các đỉnh của tam giác
void Triangle::rotateTriangle(float angle, Point2D P) {
    A.rotatePoint(angle, P);
    B.rotatePoint(angle, P);
    C.rotatePoint(angle, P);
}

void Triangle::chooseBoard() {
    //Tạo bảng chọn yêu cầu
    PutLine;
    int choose;
    cout << "\n...Chon yeu cau...";
    cout << "\n  1. Tinh tien tam giac.";
    cout << "\n  2. Phong to tam giac.";
    cout << "\n  3. Thu nho tam giac.";
    cout << "\n  4. Xoay tam giac.";
    cout << "\n  0. Thoat.";
    do {
        cout << "\n-> Chon yeu cau: ";
        cin >> choose;
    } while (choose < 0 || choose > 4);

    //Xuất các toạ độ điểm hiện tại của tam giác
    cout << "\n-> Toa do cac diem hien tai\n";
    putTriangle();

    switch (choose) {
    case 1: { //Tịnh tiến tam giác
        float dx, dy;
        cout << "\n...Tinh tien tam giac ABC...\n";
        cout << "   - Nhap hoanh do: "; cin >> dx;
        cout << "   - Nhap tung do: " ; cin >> dy;
        cout << "-> Toa do cac dinh moi\n";
        moveTriangle(dx, dy);
        putTriangle();
        break;
    }

    case 2: { //Phóng to tam giác ABC (hệ số phóng to khác 0)
        float   scale;
        Point2D center;
        cout << "\n...Phong to tam giac ABC...\n";
        do {
            cout << " *Nhap he so phong to: ";
            cin >> scale;
        } while (!scale);
    
        cout << " *Nhap diem goc phong to:\n";
        center.inputPoint();
    
        cout << "-> Toa do cac dinh moi\n";
        enlargeTriangle(scale, center);
        putTriangle();
        break;
    }

    case 3: { //Thu nhỏ tam giác ABC (hệ số thu nhỏ khác 0)
        float   scale;
        Point2D center;
        cout << "\n...Thu nho tam giac ABC...\n";
        do {
            cout << " *Nhap he so thu nho: ";
            cin >> scale;
        } while (!scale);
    
        cout << " *Nhap diem goc thu nho:\n";
        center.inputPoint();
    
        cout << "-> Toa do cac dinh moi\n";
        shrinkTriangle(scale, center);
        putTriangle();
        break;
    }

    case 4: { //Xoay tam giác ABC
        float angle;
        Point2D center;
        cout << "\n...Xoay tam giac ABC...\n";
        cout << " *Nhap goc xoay: "; cin >> angle;

        cout << " *Nhap diem goc xoay:\n";
        center.inputPoint();

        cout << "-> Toa do cac dinh moi\n";
        rotateTriangle(angle, center);
        putTriangle();
        break;
    }

    case 0: //Thoát chương trình
        exit(0);
    }
}