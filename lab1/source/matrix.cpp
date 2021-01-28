#include "matrix.h"

int min(int a, int b, int c)
{
    int res = min(a, b);
    return min(res, c);
}

void createMatr(int ***matr, int numRows, int numColumns, int elem)
{
    allocateMatr(matr, numRows, numColumns);
    initializeMatr(matr, numRows, numColumns, elem);
}

void allocateMatr(int ***matr, int numRows, int numColumns)
{
    (*matr) = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        (*matr)[i] = new int [numColumns];
    }
}

void initializeMatr(int ***matr, int numRows, int numColumns, int elem)
{

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            (*matr)[i][j] = elem;
        }
    }
}

void freeMatr(int ***matr, int numRows)
{
    for (int i = 0; i < numRows; i++) {
        free((*matr)[i]);
    }
    free((*matr));
}

void outputMatr(int **matr, int numRows, int numColumns)
{
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
