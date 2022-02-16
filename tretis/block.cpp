#include "block.h"

float block::getSize()
{
  return this->size;
}

void block::setSize(float size)
{
  this->size = size;
  
  for(int i = 0; i < 4; i++)
  {
    cubes[i].setSize(sf::Vector2f(size,size));
  }

}

void block::drawCubes(sf::RenderWindow& window)
{
  for(int i = 0; i < cubes.size(); i++)
  {
    window.draw(cubes[i]);
  }
}

void block::setColor(sf::Color color, sf::Color outline)
{
  for(int i = 0; i < cubes.size(); i++)
  {
    cubes[i].setFillColor(color);
    cubes[i].setOutlineColor(outline);
    cubes[i].setOutlineThickness(-1);
  }
}


//moves the shape
void block::teleport(float posx, float posy)
{
  float oldx = cubes[1].getPosition().x;
  float oldy = cubes[1].getPosition().y;

  float x = posx - oldx;
  float y = posy - oldy;
  
  for(int i = 0; i < cubes.size(); i++)
  {
    cubes[i].setPosition(cubes[i].getPosition().x + x, cubes[i].getPosition().y + y);
  }
  
}

block::block()
{
  //there are 4 cubes in all tetris shapes
  cubes.resize(4);
  //default size is 10 per cube
  block::setSize(10);

  
}
