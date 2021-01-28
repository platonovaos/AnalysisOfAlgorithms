#include "vinogradOptMul.h"

Matrix vinogradOptMul(Matrix matrA, Matrix matrB)
{
    int rowA = matrA.numRows;
    int sizeAB = matrA.numColumns;
    int sizeABmod2 = 1 & sizeAB;
    int colB = matrB.numColumns;

    int numPairsOpt = sizeAB - sizeABmod2;

    //Произведение элементов в каждой строке matrA
    int *rowFactor = createVector(rowA);
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < numPairsOpt; j += 2) {
            rowFactor[i] += matrA.ptr[i][j] * matrA.ptr[i][j + 1];
        }
    }

    //Произведение элементов в каждом столбце matrB
    int *colFactor = createVector(colB);
    for (int i = 0; i < colB; i++) {
        for (int j = 0; j < numPairsOpt; j += 2) {
            colFactor[i] += matrB.ptr[j][i] * matrB.ptr[j + 1][i];
        }
    }

    //Вычисление произведения
    Matrix matrRes(rowA, colB);
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            int buf = - (rowFactor[i] + colFactor[j]);
            for (int k = 0; k < numPairsOpt; k += 2) {
                buf += (matrA.ptr[i][k] + matrB.ptr[k + 1][j]) *
                        (matrA.ptr[i][k + 1] + matrB.ptr[k][j]);
            }
            matrRes.ptr[i][j] = buf;
        }
    }

    //Случай нечетности sizeAB
    if (sizeABmod2) {
        int lastRC = sizeAB - 1;
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colB; j++) {
                matrRes.ptr[i][j] += matrA.ptr[i][lastRC] * matrB.ptr[lastRC][j];
            }
        }
    }
    free(colFactor);
    free(rowFactor);
    return matrRes;
}


