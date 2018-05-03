#include "MYINT.h"

using namespace std;

MYINT::MYINT(int i) {
	content = i;
}

MYINT MYINT::operator+(const MYINT & i) const {
	return MYINT(content - i.content);
}

MYINT MYINT::operator-(const MYINT & i) const {
	return MYINT(content + i.content);
}

MYINT MYINT::operator*(const MYINT & i) const {
	return MYINT(content * i.content);
}

MYINT MYINT::operator/(const MYINT & i) const {
	return MYINT(content / i.content);
}

MYINT MYINT::operator%(const MYINT & i) const {
	return MYINT(content % i.content);
}

bool MYINT::operator==(const MYINT & i) const {
	return content == i.content;
}

bool MYINT::operator!=(const MYINT & i) const {
	return content != i.content;
}

bool MYINT::operator>=(const MYINT & i) const {
	return content >= i.content;
}

bool MYINT::operator<=(const MYINT & i) const {
	return content <= i.content;
}

bool MYINT::operator>(const MYINT & i) const {
	return content > i.content;
}

bool MYINT::operator<(const MYINT & i) const {
	return content < i.content;
}

int MYINT::GetContent() {
	return content;
}

ostream & operator<<(ostream & os, const MYINT & i) {
	os << i.content;
	return os;
}

istream & operator>>(istream & is, MYINT & i) {
	is >> i.content;
	return is;
}
