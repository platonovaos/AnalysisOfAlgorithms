#ifndef PARALLELVECTORS_H
#define PARALLELVECTORS_H

#include "matr.h"

Matrix parallelVectors(Matrix matrA, Matrix matrB, int numThreads);
void threadVectorRow(Matrix matrA, int* rowFactor, int beginRow, int endRow);
void threadVectorCol(Matrix matrB, int* colFactor, int beginCol, int endCol);

#endif // PARALLELVECTORS_H
