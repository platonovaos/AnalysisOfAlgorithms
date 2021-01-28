#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array
{
public:
    Array();
    Array(int _numElems);

    int *ptr;
    int numElems;

    void initialize(int value);
    void allocate();
    void freem();
    void output(string msg);
};

#endif
