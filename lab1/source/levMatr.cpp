#include "levMatr.h"

int LevensteinMatr(string str1, string str2, bool output)
{
    int len1 = static_cast<int>(str1.length() + 1);
    int len2 = static_cast<int>(str2.length() + 1);

    int **matr = nullptr;
    allocateMatr(&matr, len1, len2);

    //Заполнение матрицы(тривиальные случаи)
    matr[0][0] = 0;
    for (int i = 1; i < len1; i++) {
        matr[i][0] = i;
    }
    for (int j = 1; j < len2; j++) {
        matr[0][j] = j;
    }

    //Нетривиальные - минимум
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            int fine = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matr[i][j] = min(matr[i - 1][j] + 1,                    //Удаление
                            matr[i][j - 1] + 1,                     //Вставка
                            matr[i - 1][j - 1] + fine);             //Замена

        }
    }

    int res = matr[len1 - 1][len2 - 1];
    if (output) {
        outputMatr(matr, len1, len2);
    }
    freeMatr(&matr, len1);

    return res;
}
