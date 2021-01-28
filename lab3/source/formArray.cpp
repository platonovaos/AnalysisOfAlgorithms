#include "formArray.h"

void formArray(Array &arr)
{
    cout << "\nArray creation\n";
    getSize(arr);
    createArray(arr);
}

void getSize(Array &arr)
{
    cout << "\tNumber of elements:";
    cin >> arr.numElems;
}

void createArray(Array &arr)
{
    arr.allocate();
    cout << endl;
    cout << "Keyboard input.......1\n";
    cout << "Generate.............2\n\n";

    int choose = 0;
    cin >> choose;

    switch (choose) {
    case 1:
        inputElements(arr);
        break;
    case 2:
        generateArray(arr);
        break;
    }
}

void inputElements(Array &arr)
{
    cout << "Input elements.\n";

    for (int i = 0; i < arr.numElems; i++) {
        cin >> arr.ptr[i];
    }
    cout << endl;
}

void generateArray(Array &arr)
{
    for (int i = 0; i < arr.numElems; i++) {
        arr.ptr[i] = rand() % 9;
    }

    arr.output("");
}

Array copyArray(const Array arr)
{
    int numElems = arr.numElems;
    Array copyArr(numElems);
    for (int i = 0; i < copyArr.numElems; i++) {
        copyArr.ptr[i] = arr.ptr[i];
    }
    return copyArr;
}
