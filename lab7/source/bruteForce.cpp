#include "bruteForce.h"

int bruteForce(const Dictionary dict, const string searchStr)
{
    int res = -1;
    for (int i = 0; i < dict.Size; i++) {
        if (searchStr == dict.Words[i]) {
            res = i;
            break;
        }
    }
    return res;
}
