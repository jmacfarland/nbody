#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>

#include "Body.hpp"

int main(int argc, char *argv[]) {
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
  
    window.clear();
    window.draw(backgroundSprite);
    for( int i = 0; i < numberOfBodies; ++i){ // i is the body to work on
        for ( int j = 0; j < numberOfBodies; ++j){// j iterates through all the other bodies
        // lets calculate the distance between the first body in the vector and the second.
        sf::Vector2f tempvector, tempvector2, newVelocity;
        //declare and label a bunch of floats for use here
        float CONSTANT_G = 0.00000000006673;
        float distanceBetween, xdis, ydis, xdissqrd, ydissqrd, temp, distanceBetweensqrd, mass1, mass2, forcex, forcey, accelx, accely,
          velocityx, velocityy, deltaT;
        tempvector = bodies[i] -> getPos();
        tempvector2 = bodies[j] -> getPos();
        xdis = tempvector.x - tempvector2.x;
        ydis = tempvector.y - tempvector2.y;
        xdissqrd = xdis * xdis;
        ydissqrd = ydis * ydis;
        temp = xdissqrd + ydissqrd;
        distanceBetween = sqrt(temp);
        //calculate the force between the two objects
        
        float force; 
        mass1 = bodies[i] -> getMass();
        mass2 = bodies[j] -> getMass(); 
        distanceBetweensqrd = distanceBetween * distanceBetween;
        force = (CONSTANT_G * mass1 * mass2) / distanceBetweensqrd;
        //calculate the x and y components of the force ont th body
        forcex = (xdis / distanceBetween) * force;
        forcey = (ydis / distanceBetween) * force;
        // calculate the acceleration on the body's x and y components
        accelx = forcex / mass1;
        accely = forcey / mass1; 
        //calculate the new velocity
        velocityx = bodies[i] -> getVel().x;
        velocityx = velocityx * deltaT * accelx; // need to read in delta T (seconds) 

        velocityy = bodies[i] -> getVel().y;
        velocityy = velocityy * deltaT * accely;
        // update the velocity of the body
        newVelocity.x = velocityx;
        newVelocity.y = velocityy;
        bodies[i] ->setVel(newVelocity);
        }
    }

    for (int i = 0; i < (int)bodies.size(); i++) {

      window.draw(*bodies.at(i));
    }
    window.display();
  }

  return 0;
}
