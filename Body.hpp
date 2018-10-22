#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#ifndef BODY_HPP
#define BODY_HPP
//TESTING GIT
class Body : public sf::Drawable {
public:
  //Constructor, sets data equal to given values
  Body(float x_pos = 0.0, float y_pos = 0.0, float x_vel = 0.0, float y_vel = 0.0, float mass_init = 0.0, std::string filename = "earth.gif");

  //Implementation of the draw() function to allow class to be drawn to the window
  virtual void draw (sf::RenderTarget & target, sf::RenderStates states) const;

  //Getters and setters
  sf::Vector2f getPos() const;
  sf::Vector2f getVel() const;
  double getMass();
  void setPos(sf::Vector2f pos);
  void setVel(sf::Vector2f vel);
  void setAccel(float xaccel, float yaccel);
  
  //Define the oveloaded operator >>
  //friend std::istream & operator>>( std::istream &input ,Body &b);

  void setUniverseSize(float universeSize);
  void setStartPosition();
  void setMyOrigin();
  void setDeltaT(float seconds);
  void printData();

  //step function to move body based on time and current velocity
  void step(double delT);
private:
  //Separate function to update the object's Sprite
  void setupSprite(std::string filename);
  //Member Variables
  float xlocation;
  float ylocation;
  sf::Vector2f position;
  sf::Vector2f old_position;
  sf::Vector2f velocity;
  float mass;
  float universeSize;
  sf::Texture texture;
  sf::Sprite sprite;
  float X_acceleration;
  float Y_acceleration;
  float delta_T;
  std::string file;
};

 
#endif
