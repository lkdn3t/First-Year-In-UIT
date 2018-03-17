#include "Candidate.h"
using namespace std;

class TestCandidate {
private:
    int NumCdd;
    Candidate *ListCdd;

public:
    TestCandidate(int NumCdd = 0, Candidate *ListCdd = NULL);
    ~TestCandidate();
    void inputListCdd();
    void putListCdd();
    void putListPassCdd();
};