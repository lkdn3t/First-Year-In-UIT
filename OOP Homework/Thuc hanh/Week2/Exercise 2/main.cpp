#include "Complex.h"

using namespace std;

int main(int argc, char *argv[]) {
	Complex c1, c2;
	cout << "...Nhap so phuc thu nhat...\n" ; c1.input();
	cout << "\n...Nhap so phuc thu hai...\n"; c2.input();

	cout << "\n...So phuc da nhap...\n";
	cout << " So phuc thu nhat: "; c1.output();
	cout << " So phuc thu hai: " ; c2.output();

	Complex Sum     = c1.Add(c2);
	Complex Diff    = c1.Subtract(c2);
	Complex Product = c1.Multiply(c2);
	
	cout << "\n...Cac phep tinh so phuc...\n";
	cout << "\n Tong hai so phuc: "; Sum.output();
	cout << "\n Hieu hai so phuc: "; Diff.output();
	cout << "\n Tich hai so phuc: "; Product.output();

	if (!c2.getReal() && !c2.getImg()) {
		cout << "\n Khong the chia cho 0" << endl;
	}
	else {
		Complex Division = c1.Divide(c2);
		cout << "\n Thuong hai so phuc: ";
		Division.output();
	}

	cout << endl;
	system("pause");
	return 0;
}