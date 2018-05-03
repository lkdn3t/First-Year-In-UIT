#include <iostream>
#include <cmath>

using namespace std;

class Vector {
private:
	float *x;
	int NumDir;

public:
	Vector(int NumDir = 0);
	Vector(const Vector& v);
	~Vector();

public:
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector operator*(int k) const;

public:
	friend ostream& operator<<(ostream& os, const Vector& v);
	friend istream& operator>>(istream& is, Vector& v);
};

