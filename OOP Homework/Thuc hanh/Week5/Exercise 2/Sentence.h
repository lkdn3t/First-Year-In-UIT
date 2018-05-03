#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define VecStr vector<string>

using namespace std;

class Sentence {
private:
    string RawSentence;
    VecStr Words;
    int    Length;
    int    NumWords;
    void   MakeListWords();

public:
    Sentence(string RawSentence = "");
    Sentence(const Sentence& S);

public:
    void setRawSentence(string);
    void setWords(VecStr);
    void setNumWords(int);
    void setLength(int);

public:
    Sentence SortSentence()   const;
    string   getRawSentence() const;
    VecStr   getWords()       const;
    int      getNumWords()    const;
    int      getLength()      const;
};