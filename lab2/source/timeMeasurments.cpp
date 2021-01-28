#include "timeMeasurments.h"

const int numRepeats = 100;

void timeMeasurments()
{
    cout << "____________________Time________________________" << endl << endl;
    cout << "NumRowsCols | Classic | Vinograd | VinogradOptim" << endl;
    cout << "------------------------------------------------" << endl;

    createMatrixAndMeasure(20);
    createMatrixAndMeasure(21);
    createMatrixAndMeasure(30);
    createMatrixAndMeasure(31);
    createMatrixAndMeasure(40);
    createMatrixAndMeasure(41);
    createMatrixAndMeasure(50);
    createMatrixAndMeasure(51);
    createMatrixAndMeasure(100);
    createMatrixAndMeasure(101);
    createMatrixAndMeasure(200);
    createMatrixAndMeasure(201);
    cout << endl << endl;
}

void createMatrixAndMeasure(int numRowsCols)
{
    Matrix A = generateMatr(numRowsCols, numRowsCols);
    Matrix B = generateMatr(numRowsCols, numRowsCols);

    cout << numRowsCols;
    cout << setw(16) << measureClassic(A, B);
    cout << setw(10) << measureVinograd(A, B);
    cout << setw(14) << measureVinogradOptimized(A, B) << endl;
    cout << "------------------------------------------------" << endl;
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

long measureClassic(Matrix A, Matrix B)
{
    time_t begin = clock();
    for (int i = 0; i < numRepeats; i++) {
        Matrix res = standartMul(A, B);
        res.freem();
    }
    time_t end = clock();
    return ((end - begin) / numRepeats);
}

long measureVinograd(Matrix A, Matrix B)
{
    time_t begin = clock();
    for (int i = 0; i < numRepeats; i++) {
        Matrix res = vinogradMul(A, B);
        res.freem();
    }
    time_t end = clock();
    return ((end - begin) / numRepeats);
}

long measureVinogradOptimized(Matrix A, Matrix B)
{
    time_t begin = clock();
    for (int i = 0; i < numRepeats; i++) {
        Matrix res = vinogradOptMul(A, B);
        res.freem();
    }
    time_t end = clock();
    return ((end - begin) / numRepeats);
}
