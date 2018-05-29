#include "Cattle.h"
#include <vector>

void Initialize(vector<Cattle*> &cattle, int& NumCow, int& NumSheep, int& NumGoat);
void MakeAllNoise(vector<Cattle*> cattle);
string GetType(Cattle* cattle);
void ListBirthMilk(vector<Cattle*> &cattle);