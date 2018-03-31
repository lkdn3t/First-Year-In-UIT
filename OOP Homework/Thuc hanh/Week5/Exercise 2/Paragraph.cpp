#include "Paragraph.h"
#define VecSen vector<Sentence>
#define VecStr vector<string>
using namespace std;

//Make List of Sentences from a RawParagraph
void Paragraph::MakeListSentences() {
    string Sen;
    int LengthParagraph = RawParagraph.length();
    
    //Push char to Sentence till char hits ('.', '!', '?'), then push the whole Sentence to list
    for (int i = 0; i < LengthParagraph; i++) {
        Sen += RawParagraph[i];
        if (RawParagraph[i] == '.' || RawParagraph[i] == '!' || RawParagraph[i] == '?') {
            Sentence RawSentence(Sen);
            Sentences.push_back(RawSentence);
            Sen = "";
        }
    }
}

//Make List Words of Paragraph by List Words of Sentences
void Paragraph::MakeListWords() {
    for (int i = 0; i < NumSentences; i++) {
        VecStr WordsInSen = Sentences[i].getWords();
        int NumWordsInSen = Sentences[i].getNumWords();
        for (int j = 0; j < NumWordsInSen; j++)
            Words.push_back(WordsInSen[j]);
    }
}

//Construtor to set properties for Paragraph from a RawParagraph
Paragraph::Paragraph(string RawPrg) {
    RawParagraph = RawPrg;
    MakeListSentences();
	NumSentences = Sentences.size();
    MakeListWords();
}

//Copy constructor to set properties for Paragraph form another one
Paragraph::Paragraph(const Paragraph &prg):
    RawParagraph(prg.RawParagraph),
    Sentences(prg.Sentences),
    Words(prg.Words),
    NumSentences(prg.NumSentences) {}

//Properties getter from Paragraph
string Paragraph::getRawParagraph()        { return RawParagraph; }
VecSen Paragraph::getSentences()           { return Sentences;    }
VecStr Paragraph::getWords()               { return Words;        }
int    Paragraph::getNumSentences()        { return NumSentences; }

//Properties setter for Paragraph
void Paragraph::setRawParagraph(string RP) { RawParagraph = RP;   }
void Paragraph::setSentences(VecSen Sens)  { Sentences = Sens;    }
void Paragraph::setWords(VecStr Wrds)      { Words = Wrds;        }
void Paragraph::setNumSentences(int NSen)  { NumSentences = NSen; }

//Find list of most-appear-words in Paragraph
VecStr Paragraph::MostWordsInParagraph() const {
    string MostWords;
    VecStr Result;
    int MaxCount = 0;
    int NumWords = Words.size();

    for (int i = 0; i < NumWords; i++) {
        int counter = 1;
        for (int j = i + 1; j < NumWords; j++)
            if (Words[i] == Words[j])
                counter++;
   
        if (counter == MaxCount) Result.push_back(Words[i]);
        else if (counter > MaxCount) {
            while (!Result.empty()) Result.pop_back();
            Result.push_back(Words[i]);
            MaxCount = counter;
        }
    }
    return Result;
}

//Make the Sort-Paragraph with sorted Sentences
Paragraph Paragraph::SortParagraph() const {
    int NumSentences = Sentences.size();
    VecSen SortSentences;
    for (int i = 0; i < NumSentences; i++)
        SortSentences.push_back(Sentences[i].SortSentence());
    
    string SortRawParagraph;
    for (int i = 0; i < NumSentences; i++)
        SortRawParagraph += SortSentences[i].getRawSentence() + " ";
    SortRawParagraph.erase(SortRawParagraph.length() - 1, 1);

    return Paragraph(SortRawParagraph);
}