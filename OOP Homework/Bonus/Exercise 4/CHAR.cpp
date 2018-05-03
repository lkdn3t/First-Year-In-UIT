#include "CHAR.h"

CHAR::CHAR(char c) {
	content = c;
}

char CHAR::getContent() {
	return content;
}

bool CHAR::operator==(const CHAR & c) const {
	return content == c.content;
}

bool CHAR::operator!=(const CHAR & c) const {
	return content != c.content;
}
