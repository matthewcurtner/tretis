#include "shapes.h"

//TODO make a move function so you can set the position that the shape spawns at
//TODO make a fall function that 

//Forms the shape into its desired form based on size.
void shapeL::form(float size)
{
    shapeL::cubes[0].setPosition(size,size);
    shapeL::cubes[1].setPosition(size,size*2); // "center" the point it rotates around
    shapeL::cubes[2].setPosition(size,size*3); // "buddy" center point's best bud
    shapeL::cubes[3].setPosition(size*2,size*3);
}

//rotates the shape...
void shapeL::rotate()
{
    sf::Vector2f center = shapeL::cubes[1].getPosition();
    sf::Vector2f buddy = shapeL::cubes[2].getPosition();

    if(center.x == buddy.x && center.y < buddy.y)
    {
        shapeL::cubes[0].setPosition(center.x + shapeL::size, center.y); 
        shapeL::cubes[2].setPosition(center.x - shapeL::size, center.y); 
        shapeL::cubes[3].setPosition(center.x - shapeL::size, center.y + shapeL::size);
    }   
    if(center.y == buddy.y && center.x > buddy.x)
    {
        shapeL::cubes[0].setPosition(center.x, center.y + shapeL::size); 
        shapeL::cubes[2].setPosition(center.x, center.y - shapeL::size); 
        shapeL::cubes[3].setPosition(center.x - shapeL::size,center.y - shapeL::size);  
    }
    if(center.x == buddy.x && center.y > buddy.y)
    {
        shapeL::cubes[0].setPosition(center.x - shapeL::size, center.y);
        shapeL::cubes[2].setPosition(center.x + shapeL::size, center.y);
        shapeL::cubes[3].setPosition(center.x + shapeL::size, center.y - shapeL::size);
    }
    if(center.y == buddy.y && center.x < buddy.x)
    {
        shapeL::cubes[0].setPosition(center.x, center.y - shapeL::size); 
        shapeL::cubes[2].setPosition(center.x, center.y + shapeL::size); 
        shapeL::cubes[3].setPosition(center.x + shapeL::size, center.y + shapeL::size);
    }
}

shapeL::shapeL()
{
    block();
    form(size);
}

//

void shapeJ::form(float size)
{
    shapeJ::cubes[0].setPosition(size,size);
    shapeJ::cubes[1].setPosition(size,size*2); // center
    shapeJ::cubes[2].setPosition(size,size*3); // buddy
    shapeJ::cubes[3].setPosition(size-size,size*3);
}

shapeJ::shapeJ()
{
    block();
    form(size);
}



/*
 _
//\
V  \
 \  \_
  \,'.`-.
   |\ `. `.       
   ( \  `. `-.                        _,.-:\
    \ \   `.  `-._             __..--' ,-';/
     \ `.   `-.   `-..___..---'   _.--' ,'/
      `. `.    `-._        __..--'    ,' /
        `. `-_     ``--..''       _.-' ,'
          `-_ `-.___        __,--'   ,'
             `-.__  `----"""    __.-'
hh                `--..____..--'
*/
