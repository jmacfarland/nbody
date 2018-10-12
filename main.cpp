#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Body.hpp"

int main(int argc, char* argv[])
{
  int x = 800;
  int y = 600;
  sf::RenderWindow window(sf::VideoMode(x, y), "NBody Simulation");

  std::vector<Body> bodies;

  //Test code to draw Earth in the simulation- I've setup the default constructor
  //to create a Body with 0 everything, and sprite earth.gif
  Body earth;
  bodies.push_back(earth);

  while (window.isOpen())
      {
          sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window.close();
          }

          window.clear();
          for(int i = 0; i < (int)bodies.size(); i++)
          {
            window.draw(bodies.at(i));
          }
          window.display();
      }


  return 0;
}
