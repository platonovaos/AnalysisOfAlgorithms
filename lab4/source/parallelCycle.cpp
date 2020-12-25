#include "parallelCycle.h"

Matrix parallelCycle(Matrix matrA, Matrix matrB, int numThreads)
{
    int rowA = matrA.numRows;
    int sizeAB = matrA.numColumns;
    int colB = matrB.numColumns;

    int numPairs = sizeAB / 2;

    //Произведение элементов в каждой строке matrA
    int *rowFactor = createVector(rowA);
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < numPairs; j++)
        {
            rowFactor[i] += matrA.ptr[i][2 * j] * matrA.ptr[i][2 * j + 1];
        }
    }

    //Произведение элементов в каждом столбце matrB
    int *colFactor = createVector(colB);
    for (int i = 0; i < colB; i++)
    {
        for (int j = 0; j < numPairs; j++)
        {
            colFactor[i] += matrB.ptr[2 * j][i] * matrB.ptr[2 * j + 1][i];
        }
    }

    Matrix matrRes(rowA, colB);

    //Создание потоков
    thread* threads = new thread[numThreads];
    int rowsPerThred = rowA / numThreads;
    int beginRow = 0;

    for (int i = 0; i < numThreads; i++)
    {
        int endRow = beginRow + rowsPerThred;
        if (i == numThreads - 1)
        {
            endRow = rowA;
        }

        threads[i] = thread(threadCycle, matrA, matrB, matrRes,
                                        rowFactor, colFactor, beginRow, endRow);
        beginRow = endRow;
    }

    for (int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }

    //Случай нечетности
    if (sizeAB % 2 != 0)
    {
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colB; j++)
            {
                matrRes.ptr[i][j] += matrA.ptr[i][sizeAB - 1] * matrB.ptr[sizeAB - 1][j];
            }
        }
    }

    free(colFactor);
    free(rowFactor);

    return matrRes;
}

void threadCycle(Matrix matrA, Matrix matrB, Matrix matrRes,
                 int* rowFactor, int* colFactor, int beginRow, int endRow)
{
    //Вычисление произведения
    for (int i = beginRow; i < endRow; i++)
    {
        for (int j = 0; j < matrB.numColumns; j++)
        {

            matrRes.ptr[i][j] -= rowFactor[i] + colFactor[j];

            for (int k = 0; k < matrB.numRows / 2; k++)
            {
                matrRes.ptr[i][j] += (matrA.ptr[i][2 * k + 1] + matrB.ptr[2 * k][j]) *
                                        (matrA.ptr[i][2 * k] + matrB.ptr[2 * k + 1][j]);
            }
        }
    }
}
