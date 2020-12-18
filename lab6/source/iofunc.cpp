#include "iofunc.h"

vector<size_t> cutVector(vector<size_t> to, size_t last)
{
    size_t n = to.size();
    vector<size_t> cur;

    for (size_t i = 0; i < n; i++) {
        if (to[i] != last) {
            cur.push_back(to[i]);
        }
    }
    return cur;
}

vector<vector<size_t>> createMatr(size_t& n)
{
    FILE *f = fopen(inFile, "r");
    if (f == nullptr) {
        cout << "ERROR_READ_FILE" << endl;
        exit(1);
    }

    fscanf(f, "%ld", &n);
    cout << n << endl;
    vector<vector<size_t>> d(n);

    for (size_t i = 0; i < n; i++) {
        d[i].resize(n);
        for (size_t j = 0; j < n; j++) {
            fscanf(f, "%ld", &d[i][j]);
        }
    }

    fclose(f);

    return d;
}

void outputMatr(const size_t n, const vector<vector<size_t>> matr)
{
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matr[i][j] + 1 << " ";
        }
        cout << endl;
    }
}

void outputVector(vector<size_t> vec)
{
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] + 1 << " ";
    }
    cout << endl;
}
