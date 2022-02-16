#include <iostream>
#include "shapes.cpp"


int main()
{
  sf::RenderWindow window(sf::VideoMode(960, 540), "Tretis", sf::Style::Resize | sf::Style::Close);
  window.setFramerateLimit(60);

  shapeL cube;

  cube.teleport(20,40);
 
  cube.setColor(sf::Color::Blue, sf::Color::Red);

  cube.rotate();
  cube.teleport(100,100);
  for(int iter = 0; window.isOpen(); iter++)
  {
    window.clear();
    cube.drawCubes(window);

    window.display();
  }

}
