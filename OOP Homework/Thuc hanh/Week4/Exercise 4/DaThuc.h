#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class DaThuc {
private:
	int *heso;
	int bac;

public:
	DaThuc(); ~DaThuc();
	DaThuc(const DaThuc&);

	int fx(int) const;
	DaThuc operator+(const DaThuc&) const;
	DaThuc operator-(const DaThuc&) const;

	friend istream& operator>>(istream&, DaThuc&);
	friend ostream& operator<<(ostream&, DaThuc);
};