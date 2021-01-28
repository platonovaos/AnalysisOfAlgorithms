#ifndef MATR_H
#define MATR_H

#include <iostream>
using namespace std;

class Matrix
{
public:
    Matrix();
    Matrix(int nRows, int nColumns);

    int **ptr;
    int numRows;
    int numColumns;

    void initialize(int num);
    void allocate();
    void freem();
    void output(string msg);
};

int *createVector(int size);

#endif // MATR_H
