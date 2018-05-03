#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class CHAR {
private:
	char content;
public:
	CHAR() {};
	CHAR(char c);
	char getContent();
	bool operator==(const CHAR& c) const;
	bool operator!=(const CHAR& c) const;
};