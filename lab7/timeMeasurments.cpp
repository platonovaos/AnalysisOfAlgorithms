#include <iomanip>
#include "timeMeasurments.h"

const int numRepeats = 100;

void timeMeasurments(const Dictionary dict)
{
    cout << "_________________Time________________" << endl << endl;
    cout << " Idx | BruteForce | Binary | Segments" << endl;
    cout << "-------------------------------------" << endl;

    measure(dict, "board", -1);
    for (int i = 0; i < dict.Size; i += 50) {
        measure(dict, dict.Words[i], i);
    }
    measure(dict, "board", -1);

    cout << endl << endl;
}

void measure(const Dictionary dict, const string searchStr, const int idx)
{
    cout << idx;

    cout << setw(8) << measureBrute(dict, searchStr);
    cout << setw(11) << measureBin(dict, searchStr);
    cout << setw(11) << measureSeg(dict, searchStr) << endl;

    cout << "-------------------------------------" << endl;
}

long measureBrute(const Dictionary dict, const string searchStr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        bruteForce(dict, searchStr);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureBin(const Dictionary dict, const string searchStr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        binarySearch(dict, searchStr);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureSeg(const Dictionary dict, const string searchStr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        return segmentSearch(dict, searchStr);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}
