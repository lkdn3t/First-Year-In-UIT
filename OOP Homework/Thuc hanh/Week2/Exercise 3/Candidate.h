#include <iostream>
#include <string>
using namespace std;

struct Date {
        int day;
        int month;
        int year;
}; 

class Candidate {
private:
    string Name;
    string ID;
    Date  Birth;
    float MathScore;
    float LiterScore;
    float EngScore;

public:
    Candidate() {};
    void inputCandidate();
    void putCandidate();

public:
    void setName(string);
    void setID(string);
    void setBirth(int, int, int);
    void setMathScore(float);
    void setLiterScore(float);
    void setEngScore(float);

public:
    string getName() const;
    string getID() const;
    Date   getBirth() const;
    float  getMathScore() const;
    float  getLiterScore() const;
    float  getEngScore() const;
};