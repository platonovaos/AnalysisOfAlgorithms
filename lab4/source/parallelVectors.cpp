#include <thread>
#include "parallelVectors.h"

Matrix parallelVectors(Matrix matrA, Matrix matrB, int numThreads)
{
    int rowA = matrA.numRows;
    int sizeAB = matrA.numColumns;
    int colB = matrB.numColumns;

    int numPairs = sizeAB / 2;

    //Создание потоков
    thread* threads = new thread[numThreads];

    //Произведение элементов в каждой строке matrA
    int *rowFactor = createVector(rowA);
    int rowsPerThred = rowA / numThreads;
    int beginRow = 0;
    for (int i = 0; i < numThreads; i++)
    {
        int endRow = beginRow + rowsPerThred;
        if (i == numThreads - 1)
        {
            endRow = rowA;
        }

        threads[i] = thread(threadVectorRow, matrA, rowFactor, beginRow, endRow);
        beginRow = endRow;
    }

    for (int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }

    //Произведение элементов в каждом столбце matrB
    int *colFactor = createVector(colB);
    int colsPerThred = colB / numThreads;
    int beginCol = 0;
    for (int i = 0; i < numThreads; i++)
    {
        int endCol = beginCol + colsPerThred;
        if (i == numThreads - 1)
        {
            endCol = colB;
        }

        threads[i] = thread(threadVectorCol, matrB, colFactor, beginCol, endCol);
        beginCol = endCol;
    }

    for (int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }


    //Вычисление произведения
    Matrix matrRes(rowA, colB);
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            matrRes.ptr[i][j] = - rowFactor[i] - colFactor[j];
            for (int k = 0; k < numPairs; k++)
            {
                matrRes.ptr[i][j] += (matrA.ptr[i][2 * k] + matrB.ptr[2 * k + 1][j]) *
                                        (matrA.ptr[i][2 * k + 1] + matrB.ptr[2 * k][j]);
            }
        }
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

void threadVectorRow(Matrix matrA, int* rowFactor, int beginRow, int endRow)
{
    for (int i = beginRow; i < endRow; i++)
    {
        for (int j = 0; j < matrA.numColumns / 2; j++)
        {
            rowFactor[i] += matrA.ptr[i][2 * j] * matrA.ptr[i][2 * j + 1];
        }
    }
}

void threadVectorCol(Matrix matrB, int* colFactor, int beginCol, int endCol)
{
    for (int i = beginCol; i < endCol; i++)
    {
        for (int j = 0; j < matrB.numRows / 2; j++)
        {
            colFactor[i] += matrB.ptr[2 * j][i] * matrB.ptr[2 * j + 1][i];
        }
    }
}
