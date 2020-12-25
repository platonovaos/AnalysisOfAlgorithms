#include "matr.h"

Matrix::Matrix() :
    ptr(nullptr),
    numRows(0),
    numColumns(0)
{
}

Matrix::Matrix(int nRows, int nColumns):
    ptr(nullptr),
    numRows(nRows),
    numColumns(nColumns)
{
    allocate();
    initialize(0);
}

void Matrix::allocate()
{
    ptr = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        ptr[i] = new int [numColumns];
    }
}

void Matrix::initialize(int num)
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            ptr[i][j] = num;
        }
    }
}

void Matrix::freem()
{
    if (ptr != nullptr) {
        for (int i = 0; i < numRows; i++) {
            free(ptr[i]);
        }
        free(ptr);
    }
}

void Matrix::output(string msg)
{
    cout << msg << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

int *createVector(int size)
{
    int *vector = new int [size];
    for (int i = 0; i < size; i++) {
        vector[i] = 0;
    }
    return vector;
}
