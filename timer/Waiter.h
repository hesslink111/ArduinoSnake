//
// Created by Will on 11/27/2017.
//

#ifndef ARDUINO_SNAKE_WAITER_H
#define ARDUINO_SNAKE_WAITER_H


#include <functional>

class Waiter {
public:
    int handle;
    long scheduled_time;
    long interval;
    std::function<void()> func;
    Waiter(int handle, long scheduled_time, long interval, std::function<void()> func);
};


#endif //ARDUINO_SNAKE_WAITER_H
