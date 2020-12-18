#ifndef IOFUNC_H
#define IOFUNC_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

static size_t MAX = numeric_limits<size_t>::max();
static size_t L_MIN = MAX;
static vector<size_t> ROUTE_MIN;

const char inFile[] = "/home/main/Desktop/BMSTU/5sem/AnalysisOfAlgorithms/lab6/mtr10_5.txt";
const char outFile[] = "/home/main/Desktop/BMSTU/5sem/AnalysisOfAlgorithms/lab6/result.txt";

vector<size_t> cutVector(vector<size_t> to, size_t last);

vector<vector<size_t>> createMatr(size_t& n);
void outputMatr(const size_t n, const vector<vector<size_t>> matr);
void outputVector(vector<size_t> vec);

#endif // IOFUNC_H
