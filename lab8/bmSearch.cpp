#include "bmSearch.h"
#include <string.h>

const int NUM_OF_CHARS = 256;

int bmSearch(const string fullStr, const string partStr)
{
    int lenFull = static_cast<int>(fullStr.size());
    int lenPart = static_cast<int>(partStr.size());

    int stopTable[NUM_OF_CHARS + 1];
    fillStopTable(stopTable, partStr, lenPart);

    int suffixTable[lenPart];
    fillSuffixTable(suffixTable, partStr, lenPart);

    int res = -1;

    for (int i = 0; i <= lenFull - lenPart; ) {
        int j = lenPart - 1;

        while (partStr[j] == fullStr[j + i]) {
            if (j == 0) {
                res = i;
                break;
            }
            j--;
        }

        i += max(suffixTable[j], j - stopTable[fullStr[j + i]]);
    }
    return res;
}

void fillStopTable(int stopTable[], const string str, int len)
{
    for (int i = 0; i < NUM_OF_CHARS; i++) {
        stopTable[i] = -1;
    }

    for (int i = 0; i < len; i++) {
        stopTable[(int)str[i]] = i;
    }
}

void fillSuffixTable(int suffixTable[], const string str, int len)
{
    for (int i = 0; i < len; i++) {
        int offs = len;

        while (offs && !suffixMatch(str.c_str(), len, offs, i)) {
            offs--;
        }

        suffixTable[len - i - 1] = len - offs;
    }
}

int suffixMatch(const char* str, unsigned int len, unsigned int offset, unsigned int suffixlen)
{
    if (offset > suffixlen) {
        return str[offset - suffixlen - 1] != str[len - suffixlen - 1] &&
            memcmp(str + len - suffixlen, str + offset - suffixlen, suffixlen) == 0;
    } else {
        return memcmp(str + len - offset, str, offset) == 0;
    }
}
