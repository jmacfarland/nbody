

#include "Body.hpp"

Body::  Body(float x_pos = 0.0, float y_pos = 0.0, float x_vel = 0.0, float y_vel = 0.0, float mass_init = 0.0, string filename_init = "") {
  position.x = x_pos;
  position.y = y_pos;
  velocity.x = x_vel;
  velocity.y = y_vel;
  mass = mass_init;
  filename = filename_init;
}

Body::getPos
