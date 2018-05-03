#include "Student.h"
using namespace std;

int main(int argc, char *argv[]) {
    Student std;
    cout << "...Nhap thong tin sinh vien...\n";
    std.inputStudent();

    cout << "\n...Thong tin sinh vien...\n";
    std.putStudent();

    system("pause");
    return 1;
}