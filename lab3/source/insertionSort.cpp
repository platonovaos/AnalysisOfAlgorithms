#include "insertionSort.h"

void insertionSort(Array &arr)
{
    for (int i = 1; i < arr.numElems; i++) {

        int key = arr.ptr[i];
        int j = i - 1;

        while (j >= 0 && arr.ptr[j] > key) {
            arr.ptr[j + 1] = arr.ptr[j];
            j--;
        }

        arr.ptr[j + 1] = key;
    }
}
