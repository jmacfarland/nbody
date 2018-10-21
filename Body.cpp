#include "Body.hpp"
#include <iostream>
Body::Body(float x_pos, float y_pos, float x_vel, float y_vel, float mass_init,
           std::string filename) {
  position.x = x_pos;
  position.y = y_pos;
  velocity.x = x_vel;
  velocity.y = y_vel;
  mass = mass_init;
  xlocation = x_pos;
  ylocation = y_pos;
  setupSprite(filename);
  old_position.x = x_pos;
  old_position.y = y_pos;
}

void Body::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(sprite, states);
}

sf::Vector2f Body::getPos() const { return position; }

sf::Vector2f Body::getVel() const { return velocity; }

void Body::setPos(sf::Vector2f newPos) { position = newPos; }

void Body::setPos(float x, float y) {
  position.x = x;
  position.y = y;
}

double Body::getMass() {
  return mass;
}
void Body::setPos(sf::Vector2f newPos) {
  position = newPos;

}

void Body::setVel(sf::Vector2f newVel) { velocity = newVel; }

void Body::setVel(float x, float y) {
  velocity.x = x;
  velocity.y = y;
}

void Body::setAccel(float x_accel, float y_accel){
  X_acceleration = x_accel;
  Y_acceleration = y_accel;
}
 void Body::setDeltaT(float seconds){
   delta_T =  seconds;
 }
void Body::step(double deltaT){
  //update the velocity
  velocity.x = velocity.x * deltaT * X_acceleration;
  velocity.y = velocity.y * deltaT * Y_acceleration;
  //update the position
  old_position = position;
  position.x = position.x  + (velocity.x * deltaT);
  position.y = position.y + (velocity.y * deltaT);
  // move the sprite an ammount relative to the screen
  float move_x = ((position.x - old_position.x) / universeSize) * 300;
  float move_y = ((position.y - old_position.y) / universeSize) * 300; 
  sprite.move(move_x, move_y);
}
//setup sprite now also lets the location as well as the filename.
void Body::setupSprite(std::string filename)
{
  
// setup sprite now also lets the location as well as the filename.
void Body::setupSprite(std::string filename) {
  texture.loadFromFile(filename);
  sprite.setTexture(texture);
  // set to origin of the window
}

void Body::setUniverseSize(float uni) { universeSize = uni; }

void Body::setStartPosition() {
  float movex = ((xlocation / universeSize) * 300);
  float movey = ((ylocation / universeSize) * 300);
  sprite.move(movex, movey);
}

void ::Body::setMyOrigin() { sprite.setPosition(300, 300); }
