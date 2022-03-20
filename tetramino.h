#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
class tetramino
{
    public:
    //Values
    bool falling;
    float size;
    char type; //displays what shape it is
    int r_phase; //the rotation phase of the shape: 0 1 2 3
    //The blocks on the tetrimino
    std::vector<sf::Vector2f> parts;
    //constructor
    tetramino();
    //Functions
    void form(char type);
    void draw(std::vector<std::vector<bool>> grid);
    void rotate();
    void shed();
    void move(int posx, int posy);
    sf::Vector2f getPos();
};
