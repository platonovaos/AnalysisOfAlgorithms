#ifndef ANTALGORITHM_H
#define ANTALGORITHM_H

#include "iofunc.h"

void ant(size_t size, vector<vector<size_t>> matr, size_t alpha, size_t beta, double q,
         size_t time_max, ofstream& file);

bool isInRoute(size_t a, size_t b, vector<size_t> route);
vector<double> vecProbability(size_t from, vector<size_t> to,
                              vector<vector<double>> tao, vector<vector<double>> attraction,
                              size_t alpha, size_t beta);

void getRoute(vector<size_t> all, size_t start,
              vector<size_t> &route, size_t &len,
              vector<vector<size_t>> matr, vector<vector<double>> tao, vector<vector<double>> attraction,
              size_t alpha, size_t beta);



#endif // ANTALGORITHM_H
