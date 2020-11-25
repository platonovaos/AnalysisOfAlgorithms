#ifndef TIMEMEASURMENTS_H
#define TIMEMEASURMENTS_H

#include "standartSearch.h"
#include "kmpSearch.h"
#include "bmSearch.h"

void timeMeasurments();

void measure(const string fullStr, const string partStr);

long measureStandart(const string fullStr, const string partStr);
long measureKMP(const string fullStr, const string partStr);
long measureBM(const string fullStr, const string partStr);

#endif // TIMEMEASURMENTS_H
