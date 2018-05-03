#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

class String {
private:
    vector<char> str;
    int length;

public:
    String();
    String(const String&);
    String(const vector<char>&);
    void getString(int);
    void putString() const;

public:
    int getLength()  const;
    String Reverse() const;
    String Add(const String&) const;
};