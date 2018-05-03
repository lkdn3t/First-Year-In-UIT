#include <iostream>
#include <cmath>
#define elif else if

using namespace std;

class DaThuc {
private:
	float *heso = NULL;
	int bac;

public:
	DaThuc() {};
	DaThuc(const DaThuc& dt);
	~DaThuc();
	
public:
	DaThuc operator+(const DaThuc& dt) const;
	DaThuc operator-(const DaThuc& dt) const;

public:
	friend ostream& operator<<(ostream& os, const DaThuc& dt);
	friend istream& operator>>(istream& is, DaThuc& dt);
};