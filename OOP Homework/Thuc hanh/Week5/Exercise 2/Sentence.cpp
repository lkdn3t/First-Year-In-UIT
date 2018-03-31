#include "Sentence.h"
#define VecStr vector<string>
#define isAlpha(c) (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')

//Constructor to set properties for Sentence from an input string
Sentence::Sentence(string RawSentence) {
    this->Length = RawSentence.length();
    this->RawSentence = RawSentence;
    this->MakeListWords();
    this->NumWords = Words.size();
}

//Constructor to copy properties for Sentence from another one
Sentence::Sentence(const Sentence &S):
    RawSentence(S.RawSentence),
    Length(S.Length),
    Words(S.Words),
    NumWords(S.NumWords) {}

//Make a List words of the Sentence
void Sentence::MakeListWords() {
    string Word;
    char CurChar;
    bool isAlpha;
    
    for (int i = 0; i < Length; i++) {
        CurChar = RawSentence[i];
        isAlpha = isAlpha(CurChar);

        if (!isAlpha) {
            if (Word != "") Words.push_back(Word);
            Word = "";
        } else Word += CurChar;
    }
}

//Define get properties from Sentence
string Sentence::getRawSentence() const     { return RawSentence;      }
VecStr Sentence::getWords()       const     { return this->Words;      }
int    Sentence::getNumWords()    const     { return this->NumWords;   }
int    Sentence::getLength()      const     { return this->Length;     }

//Define set properties for Sentence
void Sentence::setRawSentence(string RSen)  { RawSentence    = RSen;   }
void Sentence::setWords(VecStr words)       { this->Words    = words;  }
void Sentence::setLength(int length)        { this->Length   = length; }
void Sentence::setNumWords(int nwords)      { this->NumWords = nwords; }

//Define Sort condition to sort list words of Sentence
bool SortCondition(string x, string y) {
    string lower_x, lower_y;
    int lenX = x.length();
    int lenY = y.length();    
    for (int i = 0; i < lenX; i++) lower_x += tolower(x[i]);
    for (int i = 0; i < lenY; i++) lower_y += tolower(y[i]);
    return lower_x.compare(lower_y) == -1;
}

//Ascending sort list words of a Sentence
//Sort words in RawSentence and push them back to SubSentences
Sentence Sentence::SortSentence() const {
    VecStr ListSortWords = getWords();
    int    NumWords      = getNumWords();
    string RawSen        = getRawSentence();
    string SortSentence;

    sort(ListSortWords.begin(), ListSortWords.end(), SortCondition);
    for (int i = 0; i < NumWords; i++)
        SortSentence += ListSortWords[i] + " ";

    SortSentence[0] = toupper(SortSentence[0]);
    SortSentence[SortSentence.length() - 1] = RawSen[RawSen.length() - 1];
    return Sentence(SortSentence);
}