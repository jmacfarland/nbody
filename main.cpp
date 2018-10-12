#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Body.hpp"

int main(int argc, char* argv[])
{
  int x = 800;
  int y = 600;
  sf::RenderWindow window(sf::VideoMode(x, y), "NBody Simulation");

  std::vector<sf::ConvexShape> bodies;
  bodies.push_back(new Body("nbody_files/earth.gif"));

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
