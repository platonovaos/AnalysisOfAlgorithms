#include "BruteForce.h"

void bruteForce(size_t size, vector<vector<size_t>> matr)
{
    L_MIN = MAX;
    ROUTE_MIN.clear();

    size_t l = 0;
    vector<size_t> route;
    ROUTE_MIN.resize(size + 1);
    vector<size_t> to(size - 1);

    for (size_t i = 0; i < size; i++) {
        route.clear();
        to.clear();
        l = 0;

        route.push_back(i);
        for (size_t j = 0; j < size; j++) {
            if (j != i) {
                to.push_back(j);
            }
        }
        recFunc(i, to, matr, route, l);
    }

    cout << endl << "ROUTE: ";
        outputVector(ROUTE_MIN);
    cout << "LENGHT: " << L_MIN << endl << endl;
}

void recFunc(size_t from, vector<size_t> to, vector<vector<size_t>> matr,
             vector<size_t> route, size_t l)
{

    size_t n = to.size();
    size_t last;
    if (n == 1) {
        last = to[0];

        route.push_back(last);
        l += matr[from][last];
        l += matr[last][route[0]];
        route.push_back(route[0]);

        if (l < L_MIN) {
            L_MIN = l;
            ROUTE_MIN = route;
        }
        return;
    }

    vector<size_t> cur_to(n - 1);
    vector<size_t> cur_route(n);
    size_t cur_l;
    for (size_t i = 0; i < n; i++) {
        last = to[i];
        cur_to = cutVector(to, last);
        cur_route = route;
        cur_route.push_back(last);
        cur_l = l + matr[route[route.size() - 1]][last];
        recFunc(last, cur_to, matr, cur_route, cur_l);
    }

}
