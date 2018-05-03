#include "Circle.h"

void InitializeList(Ellipse *&ellipse, Circle *&circle, int &NumEllipse, int &NumCircle);
void InputList(Ellipse *&ellipse, Circle *&circle, int NumEllipse, int NumCircle);
void OutputList(Ellipse *ellipse, Circle *circle, int NumEllipse, int NumCircle);

int main() {
	int NumEllipse, NumCircle;
	Ellipse *ellipse;
	Circle *circle;

	InitializeList(ellipse, circle, NumEllipse, NumCircle);
	InputList(ellipse, circle, NumEllipse, NumCircle);
	OutputList(ellipse, circle, NumEllipse, NumCircle);

	delete[] ellipse, circle;
	system("pause");
	return 0;
}

void InitializeList(Ellipse *& ellipse, Circle *& circle, int & NumEllipse, int & NumCircle) {
	cout << " Enter number of Ellipses: "; 
	cin >> NumEllipse;
	ellipse = new Ellipse[NumEllipse];

	cout << " Enter number of Circles: ";
	cin >> NumCircle;
	circle = new Circle[NumCircle];
}

void InputList(Ellipse *& ellipse, Circle *& circle, int NumEllipse, int NumCircle) {
	for (int i = 0; i < NumEllipse; i++) {
		cout << "\n...Enter information of Ellipse " << i + 1 << "...\n";
		ellipse[i].GetData();
	}

	for (int i = 0; i < NumCircle; i++) {
		cout << "\n...Enter information of Circle " << i + 1 << "...\n";
		circle[i].GetData();
	}
}

void OutputList(Ellipse * ellipse, Circle * circle, int NumEllipse, int NumCircle) {
	for (int i = 0; i < NumEllipse; i++) {
		cout << "\n...Information of Ellipse " << i + 1 << "...\n";
		ellipse[i].PutData();
	}

	for (int i = 0; i < NumCircle; i++) {
		cout << "\n...Information of Circle " << i + 1 << "...\n";
		circle[i].PutData();
	}
}