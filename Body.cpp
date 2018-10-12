

#include "Body.hpp"

Body::Body(float x_pos, float y_pos, float x_vel, float y_vel, float mass_init, std::string filename_init) {
  position.x = x_pos;
  position.y = y_pos;
  velocity.x = x_vel;
  velocity.y = y_vel;
  mass = mass_init;
  filename = filename_init;
}

sf::Vector2f Body::getPos() const {
  return position;
}

sf::Vector2f Body::getVel() const {
  return velocity;
}

void Body::setPos(sf::Vector2f newPos) {
  position = newPos;
}

void Body::setVel(sf::Vector2f newVel) {
  velocity = newVel;
}
