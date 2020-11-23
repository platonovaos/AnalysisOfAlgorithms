#ifndef TIMEMEASURMENTS_H
#define TIMEMEASURMENTS_H

#include "bruteForce.h"
#include "binarySearch.h"
#include "segmentSearch.h"

void timeMeasurments(const Dictionary dict);

void measure(const Dictionary dict, const string searchStr, const int idx);

long measureBrute(const Dictionary dict, const string searchStr);
long measureBin(const Dictionary dict, const string searchStr);
long measureSeg(const Dictionary dict, const string searchStr);

#endif // TIMEMEASURMENTS_H
