//
// Created by Will on 11/27/2017.
//

#ifndef ARDUINO_SNAKE_TIMER_H
#define ARDUINO_SNAKE_TIMER_H


#include <functional>
#include <list>
#include "Waiter.h"

class Timer {
private:
    int handle_num;
    std::list<Waiter *> waiters;
    void insert_waiter(Waiter *waiter);
public:
    Timer();
    int set_timeout(std::function<void()> func, int timeout);
    void clear_timeout(int timeout_handle);
    int set_interval(std::function<void()> func, int interval);
    void clear_interval(int interval_handle);

    void run_next();
};


#endif //ARDUINO_SNAKE_TIMER_H
