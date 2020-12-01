#include "conveyor.h"

const int numLines = 3;
const int numTasks = 5;

int main()
{
    vector<int> data = generateData(numTasks);
    vector<int> dataRes(numTasks);

    queue<int> queue1, queue2, queue3;

    for (int i = 0; i < numTasks; i++) {
        mutexQ1.lock();
            queue1.push(data[i]);
        mutexQ1.unlock();
    }

    clock_t begin = clock();

    thread t1(firstConveyor, queue1, queue2, queue3, numTasks);
    thread t2(secondConveyor, queue1, queue2, queue3, numTasks);
    thread t3(thirdConveyor, queue1, queue2, queue3, dataRes, numTasks);

    t1.join();
    t2.join();
    t3.join();

    clock_t end = clock();
    cout << "Time: " << end - begin << endl;

    return 0;
}
