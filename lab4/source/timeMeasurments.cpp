#include "timeMeasurments.h"
#include <chrono>

using namespace chrono;

const int numRepeats = 100;

void timeMeasurments()
{
    cout << "____________________Time_________________________" << endl << endl;
    cout << "NumRowCol  | Consist | ParalVectors | ParalCycle " << endl;
    cout << "-------------------------------------------------" << endl;

    createMatrixAndMeasure(10, 4);
    createMatrixAndMeasure(11, 4);
    createMatrixAndMeasure(20, 4);
    createMatrixAndMeasure(21, 4);
    createMatrixAndMeasure(30, 4);
    createMatrixAndMeasure(31, 4);
    createMatrixAndMeasure(40, 4);
    createMatrixAndMeasure(41, 4);
    createMatrixAndMeasure(50, 4);
    createMatrixAndMeasure(51, 4);
    createMatrixAndMeasure(100, 4);
    createMatrixAndMeasure(101, 4);
    createMatrixAndMeasure(200, 4);
    createMatrixAndMeasure(201, 4);

    cout << endl << endl;
}

void createMatrixAndMeasure(int numRowsCols, int numThreads)
{
    Matrix A = generateMatr(numRowsCols, numRowsCols);
    Matrix B = generateMatr(numRowsCols, numRowsCols);

    cout << numRowsCols;
    cout << setw(18) << measureConsist(A, B);
    cout << setw(15) << measureParalVectors(A, B, numThreads);
    cout << setw(14) << measureParalCycle(A, B, numThreads) << endl;
    cout << "-------------------------------------------------" << endl;
}

Matrix generateMatr(const int numRows, const int numCols)
{
    Matrix matr(numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matr.ptr[i][j] = rand() % 100;
        }
    }
    return matr;
}

long measureConsist(Matrix A, Matrix B)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        Matrix res = vinogradMul(A, B);
        res.freem();
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureParalVectors(Matrix A, Matrix B, int numThreads)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        Matrix res = parallelVectors(A, B, numThreads);
        res.freem();
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureParalCycle(Matrix A, Matrix B, int numThreads)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        Matrix res = parallelCycle(A, B, numThreads);
        res.freem();
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}
