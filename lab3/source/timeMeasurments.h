#ifndef TIMEMEASURMENTS_H
#define TIMEMEASURMENTS_H

#include "formArray.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "shellSort.h"

void timeMeasurments();

void createArrayAndMeasure(int numElems);
Array generateArray(const int numElems);

long measureBubble(Array arr);
long measureInsert(Array arr);
long measureShell(Array arr);

#endif // TIMEMEASURMENTS_H
