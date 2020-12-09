#include "timeMeasurments.h"

const int numRepeats = 100;

void timeMeasurments()
{
    cout << "_____________Time___________" << endl << endl;
    cout << "Length | Standart | KMP | BM" << endl;
    cout << "----------------------------" << endl;

    string fullStr = "thisisafullstr";

    for (int i = 0; i < 15; i++) {
        measure(fullStr, "afull");
        fullStr += fullStr;
    }

    cout << endl << endl;
}

void measure(const string fullStr, const string partStr)
{
    cout << fullStr.size();

    cout << setw(12) << measureStandart(fullStr, partStr);
    cout << setw(8) << measureKMP(fullStr, partStr);
    cout << setw(6) << measureBM(fullStr, partStr) << endl;

    cout << "----------------------------" << endl;
}

long measureStandart(const string fullStr, const string partStr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        standartSearch(fullStr, partStr);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureKMP(const string fullStr, const string partStr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        kmpSearch(fullStr, partStr);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureBM(const string fullStr, const string partStr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        bmSearch(fullStr, partStr);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}
