#include <iomanip>
#include "timeMeasurments.h"

const int numRepeats = 100;

void timeMeasurments()
{
    cout << "_________________Time________________" << endl << endl;
    cout << "Standart | KMP | BM" << endl;
    cout << "-------------------------------------" << endl;

    measure("abcdaeedjhka;jdhfkjvb;aaekjfablbvkasdhbclhe", "aee");

    cout << endl << endl;
}

void measure(const string fullStr, const string partStr)
{
    cout << setw(8) << measureStandart(fullStr, partStr);
    cout << setw(11) << measureKMP(fullStr, partStr);
    cout << setw(11) << measureBM(fullStr, partStr) << endl;

    cout << "-------------------------------------" << endl;
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
