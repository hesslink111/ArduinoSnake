//
// Created by Will Pease on 11/25/17.
//

#include <cstdlib>
#include <iostream>
#include "Snake.h"

Snake::Snake(int tail_x, int tail_y, int head_x, int head_y, int vect_x, int vect_y) {

    this->segments.push_front(new SnakeSegment(head_x, head_y));
    this->segments.push_back(new SnakeSegment(tail_x, tail_y));

    this->vect_x = vect_x;
    this->vect_y = vect_y;

    this->pos_x = head_x;
    this->pos_y = head_y;

    this->saved_tail = nullptr;
}

Snake::~Snake() {
    for (SnakeSegment *snake_segment : this->segments) {
        delete snake_segment;
    }
    delete this->saved_tail;
}

void Snake::move() {
    // Remove the tail;
    delete this->saved_tail;
    this->saved_tail = this->segments.back();
    this->segments.pop_back();

    // Create a new Head;
    SnakeSegment *old_head = this->segments.front();
    SnakeSegment *new_head = new SnakeSegment(old_head->pos_x + this->vect_x, old_head->pos_y + this->vect_y);
    this->segments.push_front(new_head);

    this->pos_x = new_head->pos_x;
    this->pos_y = new_head->pos_y;
}

void Snake::set_direction(int vect_x, int vect_y) {
    // Ensure allowed direction
    if(vect_x * vect_y != 0 || std::abs(vect_x + vect_y) != 1) {
        return;
    }

    // Find impossible vector
    SnakeSegment *head = this->segments.front();
    SnakeSegment *second = *std::next(this->segments.begin());

    int impos_x = second->pos_x - head->pos_x;
    int impos_y = second->pos_y - head->pos_y;

    if(vect_x == impos_x && vect_y == impos_y) {
        return;
    }

    // Set the direction as directed
    this->vect_x = vect_x;
    this->vect_y = vect_y;
}

void Snake::render(BoardState *board_state) {

    for (SnakeSegment *snake_segment : this->segments) {
        snake_segment->render(board_state);
    }
}

SnakeSegment *Snake::get_head() {
    return this->segments.front();
}

void Snake::grow() {
    this->segments.push_back(this->saved_tail);
    this->saved_tail = nullptr;
}

bool Snake::has_collided_with(Entity *entity) {
    for (SnakeSegment *snake_segment : this->segments) {
        if(snake_segment->has_collided_with(entity)) {
            return true;
        }
    }
    return false;
}
