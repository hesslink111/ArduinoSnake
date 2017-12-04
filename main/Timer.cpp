//
// Created by Will on 11/27/2017.
//

//#include <sys/time.h>

#include <utility>
#include <iostream>
#include "Timer.h"
#include <Arduino.h>

Timer::Timer() {
    this->handle_num = 0;
}

void Timer::insert_waiter(Waiter *waiter) {
    std::list<Waiter *>::iterator it;
    for(it=this->waiters.begin(); it!=this->waiters.end(); it++) {
        if(waiter->scheduled_time < (*it)->scheduled_time) {
            break;
        }
    }
    this->waiters.insert(it, waiter);
}

int Timer::set_timeout(void (*func)(), int timeout) {
    // Find time
    // struct timeval tp;
    // gettimeofday(&tp, nullptr);
    // long millis = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    long ms = millis();
    Waiter *waiter = new Waiter(this->handle_num++, ms + timeout, -1, func);

    // Insert into queue
    this->insert_waiter(waiter);
    return waiter->handle;
}

void Timer::clear_timeout(int timeout_handle) {
    for(auto it=this->waiters.begin(); it!=this->waiters.end(); it++) {
        if((*it)->handle == timeout_handle) {
            Waiter *waiter = *it;
            this->waiters.erase(it);
            delete waiter;
        }
    }
}

int Timer::set_interval(void (*func)(), int interval) {
    // Find time
    // struct timeval tp;
    // gettimeofday(&tp, nullptr);
    // long millis = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    long ms = millis();
    Waiter *waiter = new Waiter(this->handle_num++, ms + interval, interval, func);

    // Insert into queue
    this->insert_waiter(waiter);
    return waiter->handle;
}

void Timer::clear_interval(int interval_handle) {
    this->clear_timeout(interval_handle);
}

void Timer::run_next() {
    if(this->waiters.size() == 0) {
        return;
    }

    // Find current time
    Waiter *next_waiter = this->waiters.front();
    // struct timeval tp;
    // gettimeofday(&tp, nullptr);
    // long millis = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    long ms = millis();

    if(next_waiter->scheduled_time <= ms) {
        // Run scheduled waiter
        this->waiters.pop_front();
        if(next_waiter->interval > 0) {
            next_waiter->scheduled_time = ms + next_waiter->interval;
            insert_waiter(next_waiter);
            next_waiter->func();
        } else {
            next_waiter->func();
            delete next_waiter;
        }
    }
}
