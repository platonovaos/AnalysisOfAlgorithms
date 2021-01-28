#ifndef LEVRECMATR_H
#define LEVRECMATR_H

#include <limits.h>
#include "matrix.h"

int LevensteinRecMatr(string str1, string str2, bool output = true);
int levRecMatr(int ***matr, string str1, int len1, string str2, int len2);

#endif // LEVRECMATR_H
