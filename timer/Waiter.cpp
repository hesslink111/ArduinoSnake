//
// Created by Will on 11/27/2017.
//

#include "Waiter.h"

Waiter::Waiter(int handle, long scheduled_time, long interval, std::function<void()> func) {
    this->handle = handle;
    this->scheduled_time = scheduled_time;
    this->interval = interval;
    this->func = func;
}
