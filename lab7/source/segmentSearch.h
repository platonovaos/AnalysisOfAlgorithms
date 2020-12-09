#ifndef SEGMENTSEARCH_H
#define SEGMENTSEARCH_H

#include "dictFunc.h"

int segmentSearch(const Dictionary dict, const string searchStr);
int findInSegment(const Segment segment, const string searchStr);

void defineSegments(Segment segmentArray[], const int numSegments, const Dictionary dict);

void fillSegment(Segment& segment, const Dictionary dict);
void fillKey(Segment segmentArray[], const int numSegments);
void fillSize(Segment& segment, const Dictionary dict);
void sortSegments(Segment segmentArray[], const int numSegments);

void freeSegemnts(Segment segmentArray[], const int numSegments);

#endif // SEGMENTSEARCH_H
