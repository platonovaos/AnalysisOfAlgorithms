#include "vinogradMul.h"

Matrix vinogradMul(Matrix matrA, Matrix matrB)
{
    int rowA = matrA.numRows;
    int sizeAB = matrA.numColumns;
    int colB = matrB.numColumns;

    int numPairs = sizeAB / 2;

    //Произведение элементов в каждой строке matrA
    int *rowFactor = createVector(rowA);
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < numPairs; j++) {
            rowFactor[i] = rowFactor[i] + matrA.ptr[i][2 * j] * matrA.ptr[i][2 * j + 1];
        }
    }

    //Произведение элементов в каждом столбце matrB
    int *colFactor = createVector(colB);
    for (int i = 0; i < colB; i++) {
        for (int j = 0; j < numPairs; j++) {
            colFactor[i] = colFactor[i] + matrB.ptr[2 * j][i] * matrB.ptr[2 * j + 1][i];
        }
    }

    //Вычисление произведения
    Matrix matrRes(rowA, colB);
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            matrRes.ptr[i][j] = - rowFactor[i] - colFactor[j];
            for (int k = 0; k < numPairs; k++) {
                matrRes.ptr[i][j] = matrRes.ptr[i][j] + (matrA.ptr[i][2 * k] + matrB.ptr[2 * k + 1][j]) *
                                                        (matrA.ptr[i][2 * k + 1] + matrB.ptr[2 * k][j]);
            }
        }
    }

    //Случай нечетности
    if (sizeAB % 2 != 0) {
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colB; j++) {
                matrRes.ptr[i][j] = matrRes.ptr[i][j] + matrA.ptr[i][sizeAB - 1] * matrB.ptr[sizeAB - 1][j];
            }
        }
    }
    free(colFactor);
    free(rowFactor);
    return matrRes;
}
