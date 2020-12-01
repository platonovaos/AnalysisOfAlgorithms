#include "func.h"

vector<int> generateData(const int numElems)
{
    vector<int> data(numElems);

    for (int i = 0; i < numElems; i++) {
        data[i] = i;
    }

    return data;
}

void conveyorOutput(int numConv, int task, time_t tBegin, time_t tEnd)
{
    cout << "Conveyor: " << numConv << endl;
    cout << "Task: " << task << endl;
    cout << "\tTime begin: " << tBegin << endl;
    cout << "\tTime end: " << tEnd << endl;
}
