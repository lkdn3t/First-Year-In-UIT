#include "Matrix.h"
#include <ctime>
#include <cstdio>

//Lấy số hàng và số cột của ma trận
int Matrix::getCol() { return col; }
int Matrix::getRow() { return row; }

//Khởi tạo constructor và destructor
Matrix::Matrix(): row(0), col(0){}
Matrix::~Matrix() {}

//Khởi tạo số phần tử cho ma trận
void Matrix::setMatrix(int r, int c) {
	row = r; col = c;
	a = new int*[row];
	for (int i = 0; i < row; ++i)
		a[i] = new int[col];
}

//Phương thức sinh ngẫu nhiên ma trận
void Matrix::randomize() {
	cout << "- Nhap so hang: "; cin >> row;
	cout << "- Nhap so cot: ";  cin >> col;
	setMatrix(row, col);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			a[i][j] = rand() % 10;
	}
}

//Phương thức nhập ma trận
istream& operator>>(istream& is, Matrix &m) {
	cout << "- Nhap so hang: "; cin >> m.row;
	cout << "- Nhap so cot: ";  cin >> m.col;
	int row = m.row, col = m.col;
	m.setMatrix(row, col);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << "a[" << i << "," << j << "] = ";
			is >> m.a[i][j];
		}
	} return is;
}

//Phương thức xuất ma trận
ostream& operator<<(ostream& os, Matrix m) {
	int row = m.row, col = m.col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) os << "\t" << m.a[i][j];
		os << "\n\n";
	} return os;
}

//Quá tải toán tử cộng
Matrix Matrix::operator+(Matrix m) {
	Matrix Sum;
	Sum.setMatrix(row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			Sum.a[i][j] = a[i][j] + m.a[i][j];
	return Sum;
}

//Quá tải toán tử nhân
Matrix Matrix::operator*(Matrix m) {
	Matrix Pro;
	Pro.setMatrix(row, m.col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < m.col; ++j) {
			Pro.a[i][j] = 0;
			for (int k = 0; k < col; ++k)
				Pro.a[i][j] += a[i][k] * m.a[k][j];
		}
	return Pro;
}