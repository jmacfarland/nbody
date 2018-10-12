#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifndef BODY_HPP
#define BODY_HPP

class Body : public sf::Drawable {
public:
  //Constructor, sets data equal to given values
  Body(float x_pos = 0.0, float y_pos = 0.0, float x_vel = 0.0, float y_vel = 0.0, float mass_init = 0.0, std::string filename = "earth.gif");

  //Implementation of the draw() function to allow class to be drawn to the window
  virtual void draw (sf::RenderTarget & target, sf::RenderStates states) const;

  //Getters and setters
  sf::Vector2f getPos() const;
  sf::Vector2f getVel() const;

  void setPos(sf::Vector2f pos);
  void setVel(sf::Vector2f vel);
private:
  void setupSprite(std::string filename);

  sf::Vector2f position;
  sf::Vector2f velocity;
  float mass;

  sf::Texture texture;
  sf::Sprite sprite;
};

#endif
