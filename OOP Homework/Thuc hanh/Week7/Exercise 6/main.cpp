#include "Cattle.h"
#include "ListCattle.h"

int main() {
	int NumCow, NumSheep, NumGoat;
	vector<Cattle*> cattle;

	Initialize(cattle, NumCow, NumSheep, NumGoat);
	MakeAllNoise(cattle);
	ListBirthMilk(cattle);

	system("pause");
	return 0;
}