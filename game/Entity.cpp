//
// Created by Will Pease on 11/25/17.
//

#include "Entity.h"

bool Entity::has_collided_with(Entity *entity) {
    return this->pos_x == entity->pos_x && this->pos_y == entity->pos_y;
}

bool Entity::is_out_of_bounds() {
    return this->pos_x < 0 || this->pos_y >= 10 || this->pos_y < 0 || this->pos_y >= 10;
}
