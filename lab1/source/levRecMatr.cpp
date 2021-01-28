#include "levRecMatr.h"
#include "levMatr.h"

const int MAX = INT_MAX;

int LevensteinRecMatr(string str1, string str2, bool output)
{
    int len1 = static_cast<int>(str1.length() + 1);
    int len2 = static_cast<int>(str2.length() + 1);

    int **matr = nullptr;
    createMatr(&matr, len1, len2, MAX);

    int res = levRecMatr(&matr, str1, len1-1, str2, len2-1);
    if (output) {
        outputMatr(matr, len1, len2);
    }
    freeMatr(&matr, len1);

    return res;
}

int levRecMatr(int ***matr, string str1, int len1, string str2, int len2)
{
    if (len1 == 0 || len2 == 0) {
        return abs(len2 - len1);
    }

    if ((*matr)[len1][len2] == MAX) {
        int fine = (str1[len1 - 1] == str2[len2 - 1]) ? 0 : 1;

        int deletion = levRecMatr(matr, str1, len1 - 1, str2, len2) + 1;
        int insert = levRecMatr(matr, str1, len1, str2, len2 - 1) + 1;
        int replace = levRecMatr(matr, str1, len1 - 1, str2, len2 - 1) + fine;

        (*matr)[len1][len2] = min(deletion, insert, replace);
    }

    return (*matr)[len1][len2];
}
