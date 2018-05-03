#include "Polygon.h"
using namespace std;

int main(int argc, char *argv[]) {
    cout << "...Nhap da giac...\n";
    Polygon polygon;
    polygon.getPolygon();

    cout << "\n...Xuat da giac...\n";
    polygon.putPolygon();

    while (true) polygon.chooseBoard();
    system("pause");
    return 1;
}