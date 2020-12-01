#include "conveyor.h"

void firstConveyor(queue<int> queue1, queue<int> queue2, queue<int> queue3, const int num)
{
    int n = 0;
    while (n < num) {
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

void secondConveyor(queue<int> queue1, queue<int> queue2, queue<int> queue3, const int num)
{
    int n = 0;
    while (n < num) {
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
        conveyorOutput(1, task, begin, end);

        mutexQ3.lock();
            queue3.push(task);
        mutexQ3.unlock();

        n++;
    }
}

void thirdConveyor(queue<int> queue1, queue<int> queue2, queue<int> queue3, vector<int> dataRes, const int num)
{
    int n = 0;
    while (n < num) {
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
        conveyorOutput(1, task, begin, end);

        mutexRes.lock();
            dataRes.push_back(task);
        mutexRes.unlock();

        n++;
    }
}
