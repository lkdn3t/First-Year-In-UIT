#include "Paragraph.h"
#define VecSen vector<Sentence>
#define VecStr vector<string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream ifile;
    ifile.open("paragraph_inp.txt");

    if (!ifile) {
        cout << "Cannot open file!\n";
        return 0;
    }

    //Initialize a Paragraph form the string got from file
    string RawParagraph;
    getline(ifile, RawParagraph);
    Paragraph paragraph(RawParagraph);
    ifile.close();

    ofstream ofile;
    ofile.open("paragraph_out.txt");

    if (!ofile) {
        cout << "Cannot open file!\n";
        return 0;
    }

    //Write NumSentences and NumWords in each Sentences to file
    VecSen Sentences = paragraph.getSentences();
    int NumSentences = Sentences.size();

    ofile << NumSentences << endl;
    for (int i = 0; i < NumSentences; i++) {
        ofile << Sentences[i].getNumWords() << endl;
    }

    //Write list of most-appear-words in Paragraph to file
    VecStr MostWords = paragraph.MostWordsInParagraph();
    int NumMostWords = MostWords.size();

    for (int i = 0; i < NumMostWords; i++) {
        ofile << MostWords[i] << " ";
    }
    ofile << endl;

    //Write a SortParagraph to file
    string RawSortPrg = paragraph.SortParagraph().getRawParagraph();
    ofile << RawSortPrg << endl;
    ofile.close();
    return 1;
}