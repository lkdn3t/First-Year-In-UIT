#include "STRING.h"

using namespace std;

int main() {
	CHAR c1, c2('c');
	STRING s1, s2("s2"), s3('a'), s4(c1);
	s1.expand(c2).expand('a').expand(s2).expand("abc"); //s1: "cas2abc"
	s1.remove(c2).remove('d'); //s1: "as2ab"
	s1.input();
	cout << s1.getContent() << endl;
	cout << c1.getContent();

	system("pause");
	return 0;
}