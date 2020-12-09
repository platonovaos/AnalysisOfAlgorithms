#ifndef BMSEARCH_H
#define BMSEARCH_H

#include "strFunc.h"

int bmSearch(const string fullStr, const string partStr);

void fillStopTable(int stopTable[], const string str, int len);
void fillSuffixTable(int suffixTable[], const string str, int len);
int suffixMatch(const char* str, unsigned int len, unsigned int offset, unsigned int suffixlen);

#endif // BMSEARCH_H
