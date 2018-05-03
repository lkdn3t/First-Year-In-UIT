#include "Sentence.h"
#define VecSen vector<Sentence>
#define VecStr vector<string>
using namespace std;

class Paragraph {
private:
    string RawParagraph;
    VecSen Sentences;
    VecStr Words;
    int    NumSentences;

private:
    void MakeListWords();
    void MakeListSentences();

public:
    void setRawParagraph(string);
    void setSentences(VecSen);
    void setWords(VecStr);
    void setNumSentences(int);

public:
    string getRawParagraph();
    VecSen getSentences();
    VecStr getWords();
    int    getNumSentences();

public:
    Paragraph(string RawParagraph = "");
    Paragraph(const Paragraph&);
    VecStr MostWordsInParagraph() const;
    Paragraph SortParagraph() const;
};