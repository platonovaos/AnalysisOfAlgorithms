#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include "func.h"

static mutex mutexQ1, mutexQ2, mutexQ3, mutexRes;

void firstConveyor(queue<int> queue1, queue<int> queue2, queue<int> queue3, const int num);
void secondConveyor(queue<int> queue1, queue<int> queue2, queue<int> queue3, const int num);
void thirdConveyor(queue<int> queue1, queue<int> queue2, queue<int> queue3, vector<int> dataRes, const int num);

#endif // CONVEYOR_H
