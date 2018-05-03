#include "Vector.h"

using namespace std;

Vector::Vector(int NumDir) {
	this->NumDir = NumDir;
	if (!NumDir) x = NULL;

	x = new float[NumDir];
	for (int i = 0; i < NumDir; i++)
		x[i] = 0;
}

Vector::Vector(const Vector & v) {
	NumDir = v.NumDir;
	x = new float[NumDir];

	for (int i = 0; i < NumDir; i++)
		x[i] = v.x[i];
}

Vector::~Vector() {
	delete[]x;
}

Vector Vector::operator+(const Vector & v) const {
	Vector SumVec(*this);
	for (int i = 0; i < NumDir; i++)
		SumVec.x[i] += v.x[i];
	return SumVec;
}

Vector Vector::operator-(const Vector & v) const {
	Vector DiffVec(*this);
	for (int i = 0; i < NumDir; i++)
		DiffVec.x[i] -= v.x[i];
	return DiffVec;
}

Vector Vector::operator*(int k) const {
	Vector ProVec(*this);
	for (int i = 0; i < NumDir; i++)
		ProVec.x[i] *= k;
	return ProVec;
}

ostream & operator<<(ostream & os, const Vector & v) {
	if (!v.NumDir) return os;

	os << "(";
	for (int i = 0; i < v.NumDir - 1; i++)
		os << v.x[i] << "; ";

	os << v.x[v.NumDir - 1] << ")";
	return os;
}

istream & operator>>(istream & is, Vector & v) {
	cout << "Nhap so chieu vector: ";
	cin >> v.NumDir;

	v.x = new float[v.NumDir];
	cout << "Nhap " << v.NumDir << " toa do: ";

	for (int i = 0; i < v.NumDir; i++) {
		is >> v.x[i];
	}
	return is;
}
