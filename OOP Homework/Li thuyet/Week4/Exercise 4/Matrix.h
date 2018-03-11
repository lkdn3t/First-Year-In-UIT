#include <iostream>
using namespace std;

class Matrix {
private:
	int row;
	int col;
	int **a;
	void setMatrix(int, int);

public:
	Matrix();
	~Matrix();

	int getRow();
	int getCol();
	void randomize();
	Matrix operator+(Matrix);
	Matrix operator*(Matrix);

	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix);
};