#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

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

  //step function to move body based on time and current velocity
  void step(float delT);
private:
  //Separate function to update the object's Sprite
  void setupSprite(std::string filename);
  float xlocation;
  float ylocation;
  sf::Vector2f position;
  sf::Vector2f velocity;
  float mass;
  float universeSize;
  sf::Texture texture;
  sf::Sprite sprite;
  float X_acceleration;
  float Y_acceleration;
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
  std::string xpostring, yposstring, xvelstring, yvelstring, massstring,imagestring;
  imagestring = tokens.back();
  tokens.pop_back();
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
//Overload the operator out of class scope as global function
 
#endif
