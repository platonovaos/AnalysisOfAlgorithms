#ifndef PEREBOR_H
#define PEREBOR_H

#include "iofunc.h"

void bruteForce(size_t size, vector<vector<size_t>> matr);

void recFunc(size_t from, vector<size_t> to, vector<vector<size_t>> matr,
             vector<size_t> route, size_t l);

#endif // PEREBOR_H
