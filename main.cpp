#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Body.hpp"

int main(int argc, char* argv[])
{
  int numberOfBodies;
  float universeSize; 
  std::vector<Body> bodies;
  std::string line;
  Body newbody;
  // read in universe size and number of bodies
  std::cin >> numberOfBodies;
  std::cout << "number of bodies" << numberOfBodies;
  std::cin >> universeSize;
  //read in the planet data


  // 600x600 window
  int x = 600;
  int y = 600;
  sf::RenderWindow window(sf::VideoMode(x, y), "NBody Simulation");

   float xpos, ypos, xvel, yvel, mass;
  std::string filename;
  for (int i = 0; i < numberOfBodies; i++){
      std::cin >> xpos;
      std:: cout << "Xposition" << xpos;
      std::cin >> ypos;
      std::cin >> xvel;
      std::cin >> yvel;
      std::cin >> mass;
      std::cin >> filename;
      newbody = Body(xpos, ypos, xvel, yvel, mass, filename);
      bodies.push_back(newbody);
  }
  //Test code to draw Earth in the simulation- I've setup the default constructor
  //to create a Body with 0 everything, and sprite earth.gif
  //Body earth;
  Body mars(500.0, 20.0, 2.0, 1.0, 1e20, "sun.gif");
  //bodies.push_back(earth);
  bodies.push_back(mars);
 

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
            //bodies[i].setRelativePosition(universeSize);
            window.draw(bodies.at(i));
           
          }
          window.display();
      }


  return 0;
}
