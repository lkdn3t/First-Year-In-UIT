#include "Square.h"

using namespace std;

int main() {
	Quadrilateral* Q = new Square();
	Q->input();
	Q->output();

	delete Q;
	system("pause");
	return 0;
}