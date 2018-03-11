#include <iostream>
using namespace std;

class DaThuc {
private:
	int *heso;
	int bac;

public:
	DaThuc(); ~DaThuc();
	DaThuc(const DaThuc&);

	int fx(int);
	DaThuc operator+(DaThuc);
	DaThuc operator-(DaThuc);

	friend istream& operator>>(istream&, DaThuc&);
	friend ostream& operator<<(ostream&, DaThuc);
};