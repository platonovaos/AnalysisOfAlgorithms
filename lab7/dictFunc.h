#ifndef DICTFUNC_H
#define DICTFUNC_H

#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const string dictFileName = "/home/main/Desktop/BMSTU/5sem/AnalysisOfAlgorithms/lab7/dictionary.txt";
const int numRows = 959;

struct Dictionary
{
    int Size = numRows;
    string Words[numRows];
};

struct Segment
{
    char Key;
    int Size;

    string* Words;
    int* OriginalIdx;
};

string inputString();
Dictionary fillDictionary();

void outputResult(int res = -1, string word = "");

#endif // DICTFUNC_H
