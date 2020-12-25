#ifndef TIMEMEASURMENTS_H
#define TIMEMEASURMENTS_H

#include <iomanip>
#include <chrono>

#include "vinogradMul.h"
#include "parallelVectors.h"
#include "parallelCycle.h"

void timeMeasurments();

void createMatrixAndMeasure(int numRowsCols, int numThreads);
Matrix generateMatr(const int numRows, const int numCols);

long measureConsist(Matrix A, Matrix B);
long measureParalVectors(Matrix A, Matrix B, int numThreads);
long measureParalCycle(Matrix A, Matrix B, int numThreads);

#endif // TIMEMEASURMENTS_H
