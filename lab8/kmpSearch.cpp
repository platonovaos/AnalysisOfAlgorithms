#include "kmpSearch.h"

int kmpSearch(const string fullStr, const string partStr)
{
    int res = -1;

    int lenFull = static_cast<int>(fullStr.size());
    int lenPart = static_cast<int>(partStr.size());

    int* prefix = definePrefix(partStr);
    int lastPrefix = 0;

    for (int i = 0; i < lenFull; i++) {
        while (lastPrefix > 0 && partStr[lastPrefix] != fullStr[i]) {
            lastPrefix = prefix[lastPrefix - 1];
        }

        if (partStr[lastPrefix] == fullStr[i]) {
            lastPrefix++;
        }

        if (lastPrefix == lenPart) {
            res = i - lenPart + 1;
            break;
        }
    }

    delete [] prefix;
    return res;
}

int* definePrefix(const string str)
{
    int len = static_cast<int>(str.size());

    int* prefix = new int[len];
    prefix[0] = 0;

    int lastPrefix = 0;

    for (int i = 1; i < len; i++) {
        while (lastPrefix > 0 && str[lastPrefix] != str[i]) {
            lastPrefix = prefix[lastPrefix - 1];
        }

        if (str[lastPrefix] == str[i]) {
            lastPrefix++;
        }

        prefix[i] = lastPrefix;
    }

    return prefix;
}
