#include <limits>
#include <cmath>
#include <ctime>

#include "AntAlgorithm.h"
#include "BruteForce.h"

int main()
{
    size_t size = 0;
    vector<vector<size_t>> matr = createMatr(size);

    outputMatr(size, matr);

    clock_t begin = clock();
        bruteForce(size, matr);
    clock_t end = clock();

    cout << "Time: " << double(end - begin) / CLOCKS_PER_SEC << endl;

    vector<size_t> alphas = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<double> qs = { 0.1, 0.2, 0.25, 0.3, 0.4, 0.5, 0.6, 0.7, 0.75, 0.8, 0.9 };
    vector<size_t> tmax = { 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    ofstream result(outFile);

    for (size_t time = 0; time < tmax.size(); time++)
        for (size_t koef = 0; koef < alphas.size(); koef++)
            for (size_t isp = 0; isp < qs.size(); isp++)
                ant(size, matr, alphas[koef], 10 - alphas[koef], qs[isp], tmax[time], result);

    result.close();

    return 0;
}
