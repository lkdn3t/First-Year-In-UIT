#include <iostream>
using namespace std;

class Foo {
public:
	Foo();
	~Foo();
};

Foo f;
int main() {
	cout << "Hello World.\n";
}

Foo::Foo() {
	cout << "Entering the Hello program saying..." << endl;
}

Foo::~Foo() {
	cout << "Then exiting...";
}
