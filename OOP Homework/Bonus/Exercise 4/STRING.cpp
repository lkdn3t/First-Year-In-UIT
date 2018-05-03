#include "STRING.h"

using namespace std;

STRING::STRING() {
	content = NULL;
	length = 0;
}

STRING::STRING(char c) {
	content = new CHAR[1];
	content[0] = c;
	length = 1;
}

STRING::STRING(const char * str) {
	length = strlen(str);
	content = new CHAR[length];
	for (int i = 0; i < length; i++)
		content[i] = str[i];
}

STRING::STRING(CHAR c) {
	content = new CHAR[1];
	content[0] = c;
}

STRING::STRING(string str) {
	length = str.length();
	content = new CHAR[length];
	for (int i = 0; i < length; i++)
		content[i] = str[i];
}

string STRING::getContent() {
	string str;
	for (int i = 0; i < length; i++)
		str += content[i].getContent();
	return str;
}

STRING& STRING::expand(CHAR c) {
	CHAR* new_content = new CHAR[length + 1];
	for (int i = 0; i < length; i++)
		new_content[i] = content[i];
	
	new_content[length] = c;
	if (content != NULL) delete[] content;
	
	this->content = new_content;
	this->length++;
	return *this;
}

STRING& STRING::expand(char c) {
	return expand(CHAR(c));
}

STRING& STRING::expand(const char * str) {
	int new_length = length + strlen(str);
	CHAR* new_content = new CHAR[new_length];

	for (int i = 0; i < length; i++)
		new_content[i] = content[i];

	for (int i = length, k = 0; i < new_length; i++, k++)
		new_content[i] = str[k];

	if (content != NULL) delete[]content;
	this->content = new_content;
	this->length  = new_length;
	return *this;
}

STRING& STRING::expand(STRING str) {
	int new_length = length + str.length;
	CHAR* new_content = new CHAR[new_length];

	for (int i = 0; i < length; i++)
		new_content[i] = content[i];

	for (int i = length, k = 0; i < new_length; i++, k++)
		new_content[i] = str.content[k];

	if (content != NULL) delete[]content;
	this->content = new_content;
	this->length = new_length;
	return *this;
}

STRING & STRING::remove(CHAR c) {
	int count = 0;
	
	for (int i = 0; i < length; i++)
		if (content[i] == c) count++;
	
	int new_length = length - count;
	CHAR* new_content = new CHAR[new_length];
	
	int k = 0;
	for (int i = 0; i < length; i++)
		if (content[i] != c)
			new_content[k++] = content[i];

	if (content != NULL) delete[]content;
	content = new_content;
	length = new_length;
	return *this;
}

STRING & STRING::remove(char c) {
	return remove(CHAR(c));
}

void STRING::input() {
	if (content != NULL) delete[]content;
	string str;
	getline(cin, str);
	*this = STRING(str);
}