#include "Body.hpp"
#include <iostream>
Body::Body(float x_pos, float y_pos, float x_vel, float y_vel, float mass_init, std::string filename) {
  position.x = x_pos; //lets assume were in a 600 x 600 window to get this baby at the origin
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
//setup sprite now also lets the location as well as the filename.
void Body::setupSprite(std::string filename)
{
  texture.loadFromFile(filename);
  sprite.setTexture(texture);
  sprite.setPosition(position); 
  
}
void Body::setRelativePosition(float universeSize){

  position.x = ((position.x / universeSize) * 600) + 300;
  position.y = ((position.y / universeSize) * 600) + 300;
  sprite.setPosition(position);    
}