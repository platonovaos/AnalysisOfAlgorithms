#ifndef PARALLELCYCLE_H
#define PARALLELCYCLE_H

#include "thread"
#include "matr.h"

Matrix parallelCycle(Matrix matrA, Matrix matrB, int numThreads);
void threadCycle(Matrix matrA, Matrix matrB, Matrix matrRes,
                 int* rowFactor, int* colFactor, int beginRow, int endRow);

#endif // PARALLELCYCLE_H
