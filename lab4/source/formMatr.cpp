#include "formMatr.h"

void formMatr(Matrix &matrA, Matrix &matrB)
{
    cout << "\nMatrix creation\n";
    do {
        getSize("First matrix", matrA);
        getSize("Second matrix", matrB);
    }
    while (sizeMismatch(matrA, matrB));

    createMatr("First matrix", matrA);
    createMatr("Second matrix", matrB);
}

void getSize(string msg, Matrix &matr)
{
    cout << msg << endl;
    cout << "\tNumber of rows:";
    cin >> matr.numRows;
    cout << "\tNumber of columns:";
    cin >> matr.numColumns;
}

bool sizeMismatch(Matrix matrA, Matrix matrB)
{
    if (matrA.numColumns != matrB.numRows) {
        cout << "Matrix sizes do not match.\n";
        cout << "Re-enter.\n";
        return true;
    }
    return false;
}

void createMatr(string msg, Matrix &matr)
{
    matr.allocate();
    cout << endl << msg << endl;
    cout << "Keyboard input.......1\n";
    cout << "Generate.............2\n";
    int choose = 0;
    cin >> choose;
    switch (choose) {
    case 1:
        inputElements(matr);
        break;
    case 2:
        generateMatr(matr);
    }
}

void inputElements(Matrix &matr)
{
    cout << "Input elements.\n";
    for (int i = 0; i < matr.numRows; i++) {
        for (int j = 0; j < matr.numColumns; j++) {
            cin >> matr.ptr[i][j];
        }
    }
    cout << endl;
}

void generateMatr(Matrix &matr)
{
    for (int i = 0; i < matr.numRows; i++) {
        for (int j = 0; j < matr.numColumns; j++) {
            matr.ptr[i][j] = rand() % 9;
        }
    }
    matr.output("");
}
