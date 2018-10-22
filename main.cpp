#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <sstream>

#include "Body.hpp"

int main(int argc, char *argv[]) {
  //double totalseconds;
  double deltaTseconds;

  double totalSeconds = atof(argv[1]);
  double simulatedSeconds = 0;
  bool simRunning = true;

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

  // setup background image
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("starfield.jpg");
  backgroundTexture.setRepeated(true);
  sf::Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0, 0, x, y));

  // Text object to display how many seconds we have simulated
  sf::Font font;
  font.loadFromFile("Ubuntu-Regular.ttf");
  sf::Text timeDisplay;
  timeDisplay.setFont(font);
  timeDisplay.setString("0");
  timeDisplay.setStyle(sf::Text::Bold);
  timeDisplay.setFillColor(sf::Color::White);
  timeDisplay.setPosition(0.0, 0.0);

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

  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(backgroundSprite);

    //Update time display
    std::stringstream ss;
    ss << simulatedSeconds;
    timeDisplay.setString(ss.str());
    window.draw(timeDisplay);

    if(simRunning){
      for( int i = 0; i < numberOfBodies; i++){ // i is the body to work on
          double yForceTotal = 0;
          double xForceTotal = 0;
          double accelx, accely, mass1, mass2;
          for ( int j = 0; j < numberOfBodies; j++){// j iterates through all the other bodies

          sf::Vector2f tempvector, tempvector2, newVelocity;
          //declare and label a bunch of floats for use here
          double CONSTANT_G = 0.00000000006673;
          double distanceBetween, xdis, ydis, xdissqrd, ydissqrd, temp, distanceBetweensqrd,forcex, forcey;
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
          double force;
          mass1 = bodies[i] -> getMass();
          mass2 = bodies[j] -> getMass();
          distanceBetweensqrd = distanceBetween * distanceBetween;
          if(distanceBetweensqrd == 0){
            force = 0;
            forcex = 0;
            forcey = 0;
          } else {
            force = (CONSTANT_G * mass1 * mass2) / distanceBetweensqrd;
            //calculate the x and y components of the force ont th body
            forcex = (xdis / distanceBetween) * force;
            forcey = (ydis / distanceBetween) * force;
          }
          xForceTotal = xForceTotal + forcex;
          yForceTotal = yForceTotal + forcey;


          }//end j
      // calculate the acceleration on the body's x and y components
          accelx = xForceTotal / mass1;
          accely = yForceTotal / mass1;
          //give the new accel to the body
          bodies[i] ->setAccel(accelx, accely);

      }//end i
    }

    for (int i = 0; i < static_cast<int>(bodies.size()); i++) {

      //bodies[i] ->printData();
      window.draw(*bodies.at(i));
      bodies[i] -> step(deltaTseconds);
      //bodies[i] ->printData();
    }
    // If we have simulated the input # of seconds, stop updating positions
    simulatedSeconds += deltaTseconds;
    if(simulatedSeconds >= totalSeconds) simRunning = false;

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
