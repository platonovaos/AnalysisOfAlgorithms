#include "shellSort.h"

const int seqLen = 40;

int increment(Array inc, int size)
{
    int p1 = 1, p2 = 1, p3 = 1;
    int s = -1;

    do {
        s++;
        if (s % 2) {
            inc.ptr[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc.ptr[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc.ptr[s] < size);

    return s > 0 ? --s : 0;
}

void shellSort(Array &arr)
{
    Array seq(seqLen);

    // вычисление последовательности приращений
    int d = increment(seq, arr.numElems);
    for (int step = d; step >= 0; step--) {

        int idx = seq.ptr[step];

        for (int i = idx; i < arr.numElems; i++) {

            int key = arr.ptr[i];
            int j = i - idx;

            while (j >= 0 && arr.ptr[j] > key) {
                arr.ptr[j + 1] = arr.ptr[j];
                j--;
            }

            arr.ptr[j + idx] = key;
        }
    }
}

