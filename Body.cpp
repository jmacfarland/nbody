#include "Body.hpp"

Body::Body(float x_pos, float y_pos, float x_vel, float y_vel, float mass_init, std::string filename) {
  position.x = x_pos;
  position.y = y_pos;
  velocity.x = x_vel;
  velocity.y = y_vel;
  mass = mass_init;

  setupSprite(filename);
}

void Body::draw(sf::RenderTarget & target, sf::RenderStates states) const {
  target.draw(sprite, states);
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

void Body::setupSprite(std::string filename)
{
  texture.loadFromFile(filename);
  sprite.setTexture(texture);
}
