 #include "bubbleSort.h"

void bubbleSort(Array &arr)
{
    for (int i = 0; i < arr.numElems - 1; i++) {
        for (int j = 1; j < arr.numElems - i; j++) {
            if (arr.ptr[j] < arr.ptr[j - 1]) {
                swap(arr.ptr[j], arr.ptr[j - 1]);
            }
        }
    }
}
