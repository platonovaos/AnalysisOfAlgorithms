#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include "func.h"

const int numLines = 3;
const int numTasks = 5;

static queue<int> queue1, queue2, queue3;
static mutex mutex1, mutex2, mutex3;
static vector<int> dataRes;

void firstConveyor()
{
    int n = 0;
    while (n < numTasks) {
        if (queue1.empty()) {
            continue;
        }

        mutex1.lock();
            int task = queue1.front();
            queue1.pop();
        mutex1.unlock();

        time_t begin = clock();
            this_thread::sleep_for(chrono::seconds(3));
        time_t end = clock();
        conveyorOutput(1, task, begin, end);

        mutex2.lock();
            queue2.push(task);
        mutex2.unlock();

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

        mutex2.lock();
            int task = queue2.front();
            queue2.pop();
        mutex2.unlock();

        time_t begin = clock();
            this_thread::sleep_for(chrono::seconds(1));
        time_t end = clock();
        conveyorOutput(2, task, begin, end);

        mutex3.lock();
            queue3.push(task);
        mutex3.unlock();

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

        mutex3.lock();
            int task = queue3.front();
            queue3.pop();
        mutex3.unlock();

        time_t begin = clock();
            this_thread::sleep_for(chrono::seconds(2));
        time_t end = clock();
        conveyorOutput(3, task, begin, end);

        dataRes.push_back(task);

        n++;
    }
}

int main()
{
    vector<int> data = generateData(numTasks);

    clock_t begin = clock();

    //Заполнение первой очереди
    for (int i = 0; i < numTasks; i++) {
        mutex1.lock();
            queue1.push(data[i]);
        mutex1.unlock();
    }

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

