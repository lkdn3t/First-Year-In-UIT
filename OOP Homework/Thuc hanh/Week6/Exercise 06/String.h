#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class String {
private:
	char *str;
	int  len;

public:
	String(const char *str = NULL);
	String(const String& s);
	~String();

public:
	void  setString(const char *str);
	char* getString() const;
	int   getLength() const;

public:
	String operator+(const String& s) const;
	bool  operator==(const String& s) const;
	bool  operator!=(const String& s) const;
	bool  operator>=(const String &s) const;
	bool  operator<=(const String &s) const;
	bool  operator>(const String& s) const;
	bool  operator<(const String& s) const;

public:
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};