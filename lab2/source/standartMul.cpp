#include "standartMul.h"

Matrix standartMul(Matrix matrA, Matrix matrB)
{
    Matrix resMatr(matrA.numRows, matrB.numColumns);

    for (int i = 0; i < matrA.numRows; i++) {
        for (int j = 0; j < matrB.numColumns; j++) {
            for (int k = 0; k < matrA.numColumns; k++) {
                resMatr.ptr[i][j] += matrA.ptr[i][k] * matrB.ptr[k][j];
            }
        }
    }
    return resMatr;
}
