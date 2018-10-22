#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>

#include "Body.hpp"

int main(int argc, char *argv[]) {
  //double totalseconds;
  double deltaTseconds;

  //totalseconds = atof(argv[1]);
  deltaTseconds = atof(argv[2]);

  int numberOfBodies;
  float universeSize;
  std::vector<Body *> bodies;
  std::string line;
  // read in universe size and number of bodies
  std::cin >> numberOfBodies;
  std::cin >> universeSize;
  // read in the planet data

  // 600x600 window
  int x = 600;
  int y = 600;
  sf::RenderWindow window(sf::VideoMode(x, y), "NBody Simulation");
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("starfield.jpg");
  backgroundTexture.setRepeated(true);
  sf::Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0, 0, x, y));

  float xpos, ypos, xvel, yvel, mass;
  std::string filename;
  for (int i = 0; i < numberOfBodies; i++) {
    std::cin >> xpos;
    std::cin >> ypos;
    std::cin >> xvel;
    std::cin >> yvel;
    std::cin >> mass;
    std::cin >> filename;
    bodies.push_back(new Body(xpos, ypos, xvel, yvel, mass, filename));
    bodies[i]->setMyOrigin();
    bodies[i]->setUniverseSize(universeSize);
    bodies[i]->setStartPosition();
  }

  while (window.isOpen()) {
    window.setFramerateLimit(60);
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(backgroundSprite);
    for( int i = 0; i < numberOfBodies; i++){ // i is the body to work on
        for ( int j = 0; j < numberOfBodies; j++){// j iterates through all the other bodies
          //Sum forces for each body i

          //Find acceleration on that body i
        }//end j
    }//end i

    for (int i = 0; i < static_cast<int>(bodies.size()); i++) {
      // step() to update position of each body

      // Draw each body
      window.draw(*bodies.at(i));
    }
    window.display();
  }

  //Print final positions, etc
  std::cout << numberOfBodies << std::endl;
  std::cout << universeSize << std::endl;
  for (int i = 0; i < static_cast<int>(bodies.size()); i++) {
    bodies[i] ->printData();
  }

  return 0;
}
