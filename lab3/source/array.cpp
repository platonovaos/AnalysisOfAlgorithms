#include "array.h"

Array::Array() :
    ptr(nullptr),
    numElems(0)
{
}

Array::Array(int _numElems):
    ptr(nullptr),
    numElems(_numElems)
{
    allocate();
    initialize(0);
}

void Array::allocate()
{
    ptr = new int [numElems];
}

void Array::initialize(int value)
{
    for (int i = 0; i < numElems; i++) {
        ptr[i] = value;
    }
}

void Array::freem()
{
    if (ptr != nullptr) {
        free(ptr);
    }
}

void Array::output(string msg)
{
    cout << msg << endl;

    for (int i = 0; i < numElems; i++) {
        cout << ptr[i] << " ";
    }

    cout << endl << endl;
}
