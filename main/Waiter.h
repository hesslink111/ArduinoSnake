//
// Created by Will on 11/27/2017.
//

#ifndef ARDUINO_SNAKE_WAITER_H
#define ARDUINO_SNAKE_WAITER_H


class Waiter {
public:
    int handle;
    long scheduled_time;
    long interval;
    void (*func)();
    Waiter(int handle, long scheduled_time, long interval, void (*func)());
};

#endif //ARDUINO_SNAKE_WAITER_H
