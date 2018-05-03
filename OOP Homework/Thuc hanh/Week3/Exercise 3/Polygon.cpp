#include "Polygon.h"
#define PutLine cout << "\n-------------------------------------------\n"
using namespace std;

//Định constructor và destructor cho đa giác
Polygon::Polygon()  {}
Polygon::~Polygon() { delete[]Point; }

//Nhập đa giác
void Polygon::getPolygon() {
    cout << "Nhap so luong diem: ";
    cin  >> NumPoint;

    Point = new Point2D[NumPoint];
    for (int i = 0; i <  NumPoint; ++i) {
        cout << "*Nhap diem P" << i + 1 << ":\n";
        Point[i].inputPoint();
    }
}

//Xuất đa giác
void Polygon::putPolygon() {
    for (int i = 0; i < NumPoint; ++i) {
        cout << "   - Diem P" << i + 1;
        Point[i].putPoint();
    }
}

//Tịnh tiến đa giác
void Polygon::movePolygon(float dx, float dy) {
    for (int i = 0; i < NumPoint; ++i)
        Point[i].movePoint(dx, dy);
}

//Phóng to đa giác
void Polygon::enlargePolygon(float scale, Point2D G) {
    for (int i = 0; i < NumPoint; ++i)
        Point[i].enlargePoint(scale, G);
}

//Thu nhỏ đa giác
void Polygon::shrinkPolygon(float scale, Point2D G) {
    enlargePolygon(1 / scale, G);
}

//Xoay đa giác
void Polygon::rotatePolygon(float angle, Point2D G) {
    for (int i = 0; i < NumPoint; ++i)
        Point[i].rotatePoint(angle, G);
}

//Bảng chọn yêu cầu
void Polygon::chooseBoard() {
    //Tạo bảng chọn yêu cầu
    PutLine;
    int choose;
    cout << "\n...Chon yeu cau...";
    cout << "\n  1. Tinh tien da giac.";
    cout << "\n  2. Phong to da giac.";
    cout << "\n  3. Thu nho da giac.";
    cout << "\n  4. Xoay da giac.";
    cout << "\n  0. Thoat.";
    do {
        cout << "\n-> Chon yeu cau: ";
        cin >> choose;
    } while (choose < 0 || choose > 4);

    //Xuất các toạ độ điểm hiện tại của đa giác
    cout << "\n-> Toa do cac diem hien tai\n";
    putPolygon();

    switch (choose) {
    case 1: { //Tịnh tiến đa giác
        float dx, dy;
        cout << "\n...Tinh tien da giac...\n";
        cout << "   - Nhap hoanh do: "; cin >> dx;
        cout << "   - Nhap tung do: " ; cin >> dy;
        cout << "-> Toa do cac dinh moi\n";
        movePolygon(dx, dy);
        putPolygon();
        break;
    }

    case 2: { //Phóng to đa giác (hệ số phóng to khác 0)
        float   scale;
        Point2D center;
        cout << "\n...Phong to da giac...\n";
        do {
            cout << " *Nhap he so phong to: ";
            cin >> scale;
        } while (!scale);
    
        cout << " *Nhap diem goc phong to:\n";
        center.inputPoint();
    
        cout << "-> Toa do cac dinh moi\n";
        enlargePolygon(scale, center);
        putPolygon();
        break;
    }

    case 3: { //Thu nhỏ đa giác (hệ số thu nhỏ khác 0)
        float   scale;
        Point2D center;
        cout << "\n...Thu nho da giac...\n";
        do {
            cout << " *Nhap he so thu nho: ";
            cin >> scale;
        } while (!scale);
    
        cout << " *Nhap diem goc thu nho:\n";
        center.inputPoint();
    
        cout << "-> Toa do cac dinh moi\n";
        shrinkPolygon(scale, center);
        putPolygon();
        break;
    }

    case 4: { //Xoay đa giác
        float angle;
        Point2D center;
        cout << "\n...Xoay da giac...\n";
        cout << " *Nhap goc xoay: "; cin >> angle;

        cout << " *Nhap diem goc xoay:\n";
        center.inputPoint();

        cout << "-> Toa do cac dinh moi\n";
        rotatePolygon(angle, center);
        putPolygon();
        break;
    }

    case 0: //Thoát chương trình
        exit(0);
    }
}