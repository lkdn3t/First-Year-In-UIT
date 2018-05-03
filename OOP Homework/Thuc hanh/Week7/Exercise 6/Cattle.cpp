#include "Cattle.h"

Cattle::Cattle() {}

int Cattle::getBirth() const {
	return Birth;
}

int Cattle::getMilk() const {
	return Milk;
}

string Cattle::getNoise() const {
	return Noise;
}

void Cattle::setBirth(int Birth) {
	this->Birth = Birth;
}

void Cattle::setMilk(int Milk) {
	this->Milk = Milk;
}

void Cattle::setNoise(string Noise) {
	this->Noise = Noise;
}

void Cattle::MakeNoise() const {
	cout << " " << Noise << endl;
}
