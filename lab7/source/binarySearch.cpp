#include "binarySearch.h"

int binarySearch(const Dictionary dict, const string searchStr)
{
    int left = 0, middle = 0, right = dict.Size;
    int res = -1;

    while (left < right) {
        middle = (left + right) / 2;

        string dStr = dict.Words[middle];

        if (searchStr < dStr) {
            right = middle;
        } else {
            if (searchStr == dStr) {
                res = middle;
                break;
            } else {
                if (searchStr > dStr) {
                    left = middle + 1;
                }
            }
        }
    }

    return res;
}
