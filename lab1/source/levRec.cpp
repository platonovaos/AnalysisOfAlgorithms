#include "levRec.h"

int LevensteinRec(string str1, string str2)
{
    int len1 = static_cast<int>(str1.length());
    int len2 = static_cast<int>(str2.length());

    return levRec(str1, len1, str2, len2);
}

int levRec(string str1, int len1, string str2, int len2)
{
    if (len1 == 0 || len2 == 0) {
        return abs(len2 - len1);
    }

    int fine = (str1[len1 - 1] == str2[len2 - 1]) ? 0 : 1;

    int deletion = levRec(str1, len1 - 1, str2, len2) + 1;
    int insert = levRec(str1, len1, str2, len2 - 1) + 1;
    int replace = levRec(str1, len1 - 1, str2, len2 - 1) + fine;

    return min(deletion, insert, replace);
}
