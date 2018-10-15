#include "Body.hpp"
#include <iostream>
Body::Body(float x_pos, float y_pos, float x_vel, float y_vel, float mass_init, std::string filename) {
  position.x = x_pos; //lets assume were in a 600 x 600 window to get this baby at the origin
  position.y = y_pos;
  velocity.x = x_vel;
  velocity.y = y_vel;
  mass = mass_init;
  xlocation = x_pos;
  ylocation = y_pos;
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
  //set to origin of the 600x600 window
  sprite.setPosition(300, 300); 
  
}
void Body::setUniverseSize(float uni){
  universeSize = uni;  
  
}

void Body::setStartPosition(){
  float movex = ((xlocation / universeSize) * 600);
  float movey = ((ylocation / universeSize) * 600);
  sprite.move(movex, movey);

}