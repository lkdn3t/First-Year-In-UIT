#include "Triangle.h"
#include "Quadrilateral.h"

int main() {
	Polygon *p = new Quadrilateral();
	p->input(); cout << endl;
	p->output();

	float dx, dy;
	cout << "\n Enter move vector: ";
	cin >> dx >> dy;

	cout << endl;
	p->move(dx, dy);
	p->output();

	delete p;
	system("pause");
	return 0;
}