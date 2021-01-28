#ifndef TIMEMEASURMENTS_H
#define TIMEMEASURMENTS_H

#include "standartMul.h"
#include "vinogradMul.h"
#include "vinogradOptMul.h"

#include <iomanip>

void timeMeasurments();

void createMatrixAndMeasure(int numRowsCols);
Matrix generateMatr(const int numRows, const int numCols);

long measureClassic(Matrix A, Matrix B);
long measureVinograd(Matrix A, Matrix B);
long measureVinogradOptimized(Matrix A, Matrix B);

#endif // TIMEMEASURMENTS_H
