#include "standartSearch.h"

int standartSearch(const string fullStr, const string partStr)
{
    int res = -1;

    int lenFull = defineLength(fullStr);
    int lenPart = defineLength(partStr);

    for (int i = 0; i <= lenFull - lenPart; i++) {

        bool areEqual = true;

        for (int j = 0; j < lenPart && areEqual; j++) {
            if (fullStr[i + j] != partStr[j]) {
                areEqual = false;
            }
        }

        if (areEqual == true) {
            res = i;
            break;
        }
    }

    return res;
}


int defineLength(const string str)
{
    int len = 0;
    for (len = 0; str[len]; len++);
    return len;
}
