#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include "func.h"

const int numLines = 3;
const int numTasks = 5;

static queue<int> queue1, queue2, queue3;
static mutex mutexQ1, mutexQ2, mutexQ3, mutexRes;
static vector<int> dataRes;

void firstConveyor()
{
    int n = 0;
    while (n < numTasks) {
        if (queue1.empty()) {
            continue;
        }

        mutexQ1.lock();
            int task = queue1.front();
            queue1.pop();
        mutexQ1.unlock();

        time_t begin = clock();
            this_thread::sleep_for(chrono::seconds(3));
        time_t end = clock();
        conveyorOutput(1, task, begin, end);

        mutexQ2.lock();
            queue2.push(task);
        mutexQ2.unlock();

        n++;
    }
}

void secondConveyor()
{
    int n = 0;
    while (n < numTasks) {
        if (queue2.empty()) {
            continue;
        }

        mutexQ2.lock();
            int task = queue2.front();
            queue2.pop();
        mutexQ2.unlock();

        time_t begin = clock();
            this_thread::sleep_for(chrono::seconds(1));
        time_t end = clock();
        conveyorOutput(2, task, begin, end);

        mutexQ3.lock();
            queue3.push(task);
        mutexQ3.unlock();

        n++;
    }
}

void thirdConveyor()
{
    int n = 0;
    while (n < numTasks) {
        if (queue3.empty()) {
            continue;
        }

        mutexQ3.lock();
            int task = queue3.front();
            queue3.pop();
        mutexQ3.unlock();

        time_t begin = clock();
            this_thread::sleep_for(chrono::seconds(2));
        time_t end = clock();
        conveyorOutput(3, task, begin, end);

        mutexRes.lock();
            dataRes.push_back(task);
        mutexRes.unlock();

        n++;
    }
}

int main()
{
    vector<int> data = generateData(numTasks);

    for (int i = 0; i < numTasks; i++) {
        mutexQ1.lock();
            queue1.push(data[i]);
        mutexQ1.unlock();
    }

    clock_t begin = clock();

    thread t1(firstConveyor);
    thread t2(secondConveyor);
    thread t3(thirdConveyor);

    t1.join();
    t2.join();
    t3.join();

    clock_t end = clock();
    cout << "Time: " << end - begin << endl;

    return 0;
}

