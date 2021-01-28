#ifndef FORMMATR_H
#define FORMMATR_H

#include "matr.h"

void formMatr(Matrix &matrA, Matrix &matrB);

void getSize(string msg, Matrix &matr);
bool sizeMismatch(Matrix matrA, Matrix matrB);

void createMatr(string msg, Matrix &matr);
void inputElements(Matrix &matr);
void generateMatr(Matrix &matr);

#endif // FORMMATR_H
