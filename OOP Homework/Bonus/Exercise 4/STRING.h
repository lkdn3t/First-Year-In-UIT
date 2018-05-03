#include "CHAR.h"

using namespace std;

class STRING {
private:
	CHAR * content;
	int length;

public:
	STRING();
	STRING(char c);
	STRING(const char *str);
	STRING(CHAR c);
	STRING(string str);
	string getContent();

	STRING &expand(CHAR c);
	STRING &expand(char c);
	STRING &expand(const char* str);
	STRING &expand(STRING str);

	STRING &remove(CHAR c);
	STRING &remove(char c);

	void input();
};

