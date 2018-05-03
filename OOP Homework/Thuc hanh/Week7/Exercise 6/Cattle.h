#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Cattle {
protected:
	int Birth;
	int Milk;
	string Noise;

public:
	Cattle();
	int getBirth() const;
	int getMilk() const;
	string getNoise() const;

public:
	void setBirth(int Birth);
	void setMilk(int Milk);
	void setNoise(string Noise);
	void MakeNoise() const;
};

class Cow : public Cattle {
public:
	Cow() {
		Birth = 1 + rand() % 3;
		Milk = rand() % 21;
		Noise = "Moooo!";
	}
};

class Sheep : public Cattle {
public:
	Sheep() {
		Birth = 1 + rand() % 2;
		Milk = rand() % 6;
		Noise = "Baaaa!";
	}
};

class Goat :public Cattle {
public:
	Goat() {
		Birth = 1 + rand() % 5;
		Milk = rand() % 11;
		Noise = "Bleat!";
	}
};