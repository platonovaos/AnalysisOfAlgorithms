#include "AntAlgorithm.h"

void ant(size_t size, vector<vector<size_t>> matr, size_t alpha, size_t beta, double q,
         size_t time_max, ofstream& file)
{
    L_MIN = MAX;
    ROUTE_MIN.clear();

    double tao_min, tao_start, Q;
    vector<size_t> all(size);
    Q = 350;
    tao_min = 0.001;
    tao_start = 0.5;

    vector<vector<size_t>> routes(size);
    vector<size_t> lens(size);

    vector<vector<double>> attraction(size);
    vector<vector<double>> tao(size);

    for (size_t i = 0; i < size; i++) {
        attraction[i].resize(size);
        tao[i].resize(size);
        lens[i] = 0;
        all[i] = i;

        for (size_t j = 0; j < size; j++) {
            if (i != j) {
                attraction[i][j] = 1.0 / matr[i][j];
                tao[i][j] = tao_start;
            }
        }
    }

    for (size_t time = 0; time < time_max; time++) {
        for (size_t k = 0; k < size; k++) {
            getRoute(all, k, routes[k], lens[k], matr, tao, attraction, alpha, beta);

            if (lens[k] < L_MIN) {
                L_MIN = lens[k];
                ROUTE_MIN = routes[k];
            }
        }

        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                double sum = 0;

                for (size_t m = 0; m < size; m++) {
                    if (isInRoute(i, j, routes[m])) {
                        sum += Q / lens[m];
                    }
                }

                tao[i][j] = tao[i][j] * (1 - q) + sum;
                if (tao[i][j] < tao_min) {
                    tao[i][j] = tao_min;
                }
            }
        }
    }

    file << " | " << time_max << " | " << alpha << " | " << beta << " | " << q << " | " << L_MIN << " | ";
    for (size_t i = 0; i < ROUTE_MIN.size(); i++)
        file << ROUTE_MIN[i] << " ";
    file << endl;
}

void getRoute(vector<size_t> all, size_t start,
              vector<size_t> &route, size_t &len,
              vector<vector<size_t>> matr, vector<vector<double>> tao, vector<vector<double>> attraction,
              size_t alpha, size_t beta)
{
    route.resize(0);
    route.push_back(start);

    vector<size_t> to = cutVector(all, start);
    size_t n_1 = tao.size() - 2;
    size_t from;

    double coin = 0, sum = 0;
    bool flag = true;

    for (size_t i = 0; i < n_1; i++) {
        sum = 0;
        flag = true;
        from = route[i];

        vector<double> p = vecProbability(from, to, tao, attraction, alpha, beta);
        coin = double(rand() % 10000) / 10000;

        for (size_t j = 0; j < p.size() && flag; j++) {
            sum += p[j];
            if (coin < sum) {
                route.push_back(to[j]);
                len += matr[from][to[j]];
                to = cutVector(to, to[j]);
                flag = false;
            }
        }
    }

    len += matr[route[route.size() - 1]][to[0]];
    route.push_back(to[0]);

    len += matr[route[route.size() - 1]][route[0]];
    route.push_back(route[0]);
}

bool isInRoute(size_t a, size_t b, vector<size_t> route)
{
    bool res = false;
    size_t m = route.size() - 1;

    for (size_t i = 0; i < m && !res; i++) {
        if (a == route[i] && b == route[i + 1]) {
            res = true;
        }
    }
    return res;
}

vector<double> vecProbability(size_t from, vector<size_t> to,
                              vector<vector<double>> tao, vector<vector<double>> attraction,
                              size_t alpha, size_t beta)
{
    double znam = 0, chisl = 0;

    size_t n = to.size();
    vector<double> result(n);

    for (size_t i = 0; i < n; i++) {
        znam += pow(tao[from][to[i]], alpha) * pow(attraction[from][to[i]], beta);
    }

    for (size_t j = 0; j < n; j++) {
        chisl = pow(tao[from][to[j]], alpha) * pow(attraction[from][to[j]], beta);
        result[j] = chisl / znam;
    }

    return result;
}
