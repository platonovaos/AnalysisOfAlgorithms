#include <iomanip>
#include "timeMeasurments.h"

const int numRepeats = 100;

void timeMeasurments()
{
    cout << "______________Time________________" << endl << endl;
    cout << "NumElems | Bubble | Insert | Shell" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 10; i < 100; i += 10) {
        createArrayAndMeasure(i);
    }

    for (int i = 100; i < 700; i += 100) {
        createArrayAndMeasure(i);
    }

    cout << endl << endl;
    cout << "Random" << endl;
}

void createArrayAndMeasure(int numElems)
{
    Array arr = generateArray(numElems);
    Array arrBubble = copyArray(arr);
    Array arrInsert = copyArray(arr);
    Array arrShell = copyArray(arr);

    cout << numElems;

    cout << setw(12) << measureBubble(arrBubble);
    cout << setw(10) << measureInsert(arrInsert);
    cout << setw(8) << measureShell(arrShell) << endl;

    cout << "----------------------------------" << endl;

    arrShell.freem();
    arrInsert.freem();
    arrBubble.freem();
    arr.freem();
}

Array generateArray(const int numElems)
{
    Array arr(numElems);
    for (int i = 0; i < numElems; i++) {
        arr.ptr[i] = random() % 100;
    }
    return arr;
}

long measureBubble(Array arr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        Array copyA = copyArray(arr);
        bubbleSort(copyA);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureInsert(Array arr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        Array copyA = copyArray(arr);
        insertionSort(copyA);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}

long measureShell(Array arr)
{
    time_t begin = clock();

    for (int i = 0; i < numRepeats; i++) {
        Array copyA = copyArray(arr);
        shellSort(copyA);
    }

    time_t end = clock();

    return (end - begin) / numRepeats;
}
