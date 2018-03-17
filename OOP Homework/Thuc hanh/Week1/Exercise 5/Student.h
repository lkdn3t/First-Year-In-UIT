#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string Name;
    float  MathScore;
    float  LiterScore;
    float  AverageScore;

public:
    Student(string Name = "", float MScore = 0, float LScore = 0);
    void computeAverage();
    void inputStudent();
    void putStudent();
};