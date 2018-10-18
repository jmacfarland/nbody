#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Body.hpp"

// Displays the final state of the universe in text format
void displayOutput() {}

int main(int argc, char *argv[]) {
  double t = std::atof(argv[1]);
  double dt = std::atof(argv[2]);
  double timeElapsed = 0;

  int numberOfBodies;
  float universeSize;
  std::vector<Body *> bodies;
  std::string line;
  // read in universe size and number of bodies
  std::cin >> numberOfBodies;
  std::cout << "number of bodies: " << numberOfBodies << std::endl;
  std::cin >> universeSize;
  std::cout << universeSize << std::endl;
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
    std::cout << "X: " << xpos << ", ";
    std::cin >> ypos;
    std::cout << "Y: " << ypos << ", ";
    std::cin >> xvel;
    std::cin >> yvel;
    std::cin >> mass;
    std::cin >> filename;
    std::cout << filename << std::endl;
    bodies.push_back(new Body(xpos, ypos, xvel, yvel, mass, filename));
    // not finshed here almost
    bodies[i]->setMyOrigin();
    bodies[i]->setUniverseSize(universeSize);
    bodies[i]->setStartPosition();
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Calculate forces acting on each Body

    // Apply forces to each Body, changing their Velocities

    // Calculate and apply new positions based on updated Velocities
    for (int i = 0; i < static_cast<int>(bodies.size()); i++) {
      bodies[i]->step(dt);
    }
    timeElapsed += dt;
    if (timeElapsed >= t) {
      window.close();
      displayOutput();
    }

    window.clear();
    window.draw(backgroundSprite);
    for (int i = 0; i < static_cast<int>(bodies.size()); i++) {

      window.draw(*bodies.at(i));
    }
    window.display();
  }

  return 0;
}
