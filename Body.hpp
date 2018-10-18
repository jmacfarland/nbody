#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#ifndef BODY_HPP_
#define BODY_HPP_
// TESTING GIT
class Body : public sf::Drawable {
public:
  // Constructor, sets data equal to given values
  Body(float x_pos = 0.0, float y_pos = 0.0, float x_vel = 0.0,
       float y_vel = 0.0, float mass_init = 0.0,
       std::string filename = "earth.gif");

  // Implementation of the draw() function to allow class to be drawn to the
  // window
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  // Moves the body over given seconds in accordance with its velocity.
  void step(double seconds);

  // Getters and setters
  sf::Vector2f getPos() const;
  sf::Vector2f getVel() const;

  void setPos(sf::Vector2f pos);
  void setPos(float x, float y);
  void setVel(sf::Vector2f vel);
  void setVel(float x, float y);

  // Define the oveloaded operator >>
  // friend std::istream & operator>>( std::istream &input ,Body &b);

  void setUniverseSize(float universeSize);
  void setStartPosition();
  void setMyOrigin();

private:
  // Separate function to update the object's Sprite
  void setupSprite(std::string filename);
  float xlocation;
  float ylocation;
  sf::Vector2f position;
  sf::Vector2f velocity;
  float mass;
  float universeSize;
  sf::Texture texture;
  sf::Sprite sprite;

  /*
  friend std::istream & operator >> (std::istream &in,  Body &b){
  std::vector <std::string> tokens;
  std::istringstream tokenstream(in);

    std::string intermediate;

    // Tokenizing w.r.t. space ' '
    while(getline(tokenstream, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
  //put the tokenized string into their seperate variables.
  std::string xpostring, yposstring, xvelstring, yvelstring,
massstring,imagestring; imagestring = tokens.back(); tokens.pop_back();
  massstring = tokens.back();
  tokens.pop_back();
  yvelstring = tokens.back();
  tokens.pop_back();
  xvelstring = tokens.back();
  tokens.pop_back();
  yposstring = tokens.back();
  tokens.pop_back();
  xpostring = tokens.back();
  tokens.pop_back();
  float xpos, ypos, xvel, yvel, mass;
  xpos = atof(xpostring);
  ypos = stof(yposstring);
  xvel = stof(xvelstring);
  yvel = stof(yvelstring);
  mass = stof(massstring);

    b = Body(xpos, ypos, xvel, yvel, mass, imagestring);
}
*/
};
// Overload the operator out of class scope as global function

#endif // BODY_HPP_
