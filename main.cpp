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
  std::cout << "delta T seconds" << deltaTseconds <<"\n";
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
        
        sf::Vector2f tempvector, tempvector2, newVelocity;
        //declare and label a bunch of floats for use here
        float CONSTANT_G = 0.00000000006673;
        double distanceBetween, xdis, ydis, xdissqrd, ydissqrd, temp, distanceBetweensqrd, mass1, mass2, forcex, forcey, accelx, accely;
        // lets calculate the distance between the first body in the vector and the second.
        tempvector = bodies[i] -> getPos();
        tempvector2 = bodies[j] -> getPos();
        xdis = tempvector.x - tempvector2.x;
        ydis = tempvector.y - tempvector2.y;
        xdissqrd = xdis * xdis; 
        ydissqrd = ydis * ydis;
        temp = xdissqrd + ydissqrd; // a square + b square
        distanceBetween = sqrt(temp); // c square
       
        //calculate the force between the two objects
        float force; 
        mass1 = bodies[i] -> getMass();
        mass2 = bodies[j] -> getMass(); 
        distanceBetweensqrd = distanceBetween * distanceBetween;
        if(distanceBetweensqrd == 0){
          force = 0;
          forcex = 0;
          forcey = 0;
        }
        else {
          force = (CONSTANT_G * mass1 * mass2) / distanceBetweensqrd;
          //calculate the x and y components of the force ont th body
          forcex = (xdis / distanceBetween) * force;
          forcey = (ydis / distanceBetween) * force;
        }
        // calculate the acceleration on the body's x and y components
        accelx = forcex / mass1;
        accely = forcey / mass1; 
        //give the new accel to the body
        bodies[i] ->setAccel(accelx, accely);
  
        }//end j
    }//end i
     
      for (int i = 0; i < (int)bodies.size(); i++) {

        bodies[i] ->printData();
        window.draw(*bodies.at(i));
        bodies[i] -> step(deltaTseconds);
        bodies[i] ->printData();
      }
      
    window.display();
  }

  return 0;
}
