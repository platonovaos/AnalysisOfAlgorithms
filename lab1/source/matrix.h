#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

int min(int a, int b, int c);

void createMatr(int ***matr, int numRows, int numColumns, int elem);
void allocateMatr(int ***matr, int numRows, int numColumns);
void initializeMatr(int ***matr, int numRows, int numColumns, int elem);

void freeMatr(int ***matr, int numRows);
void outputMatr(int **matr, int numRows, int numColumns);

#endif // MATRIX_H
