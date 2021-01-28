#ifndef TIMEMEASURE_H
#define TIMEMEASURE_H

#include <iomanip>

#include "levMatr.h"
#include "levRec.h"
#include "levRecMatr.h"
#include "demLevMatr.h"

void timeMeasurment();

void createStringAndMeasure(int len);
void LenTime(int len, string str1, string str2);

void LevMatrTime(string str1, string str2);
void LevRecTime(string str1, string str2);
void DemLevMatrTime(string str1, string str2);
void LevRecTime(int len);

#endif // TIMEMEASURE_H
