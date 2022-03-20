#include "tetramino.h"
#include <cmath>
tetramino::tetramino()
{
    parts.resize(4);
}
void tetramino::form(char type)
{
    if(type == 'L')
    {
        tetramino::type = 'L';
        parts[0].x = 5;
        parts[0].y = 0;
        parts[1].x = 5;
        parts[1].y = 1;
        parts[2].x = 5;
        parts[2].y = 2;
        parts[3].x = 6;
        parts[3].y = 2;
    }

    tetramino::r_phase = 0;
}
void tetramino::draw(std::vector<std::vector<bool>> grid)
{
    for(int i = 0; i < parts.size(); i++)
    {
        grid[parts[i].y][parts[i].x] = 1;
    }
}
void tetramino::rotate()
{
    std::vector<std::vector<int>> grid;
    grid.resize(24);
    for(int y = 0; y < grid.size();y++)
    {
        grid[y].resize(12);
    }

    sf::Vector2f p0;
    sf::Vector2f p2;
    sf::Vector2f p3;

    int backupr = tetramino::r_phase;
    sf::Vector2f backup0 = tetramino::parts[0];
    sf::Vector2f backup1 = tetramino::parts[1];
    sf::Vector2f backup2 = tetramino::parts[2];
    sf::Vector2f backup3 = tetramino::parts[3];

    sf::Vector2f p1 = tetramino::parts[1]; //the center piece that the shape rotates around(in some cases)
    if(tetramino::type == 'L')
    {
        
        if(tetramino::r_phase == 0)
        {
            p0 = sf::Vector2f(p1.x + 1, p1.y);
            p2 = sf::Vector2f(p1.x - 1, p1.y);
            p3 = sf::Vector2f(p1.x - 1, p1.y + 1);
            tetramino::r_phase = 1;
        }
        else if(tetramino::r_phase == 1)
        {
            p0 = sf::Vector2f(p1.x, p1.y + 1);
            p2 = sf::Vector2f(p1.x, p1.y - 1);
            p3 = sf::Vector2f(p1.x - 1, p1.y - 1);  
            tetramino::r_phase = 2;
        }
        else if(tetramino::r_phase == 2)
        {
            p0 = sf::Vector2f(p1.x - 1, p1.y);
            p2 = sf::Vector2f(p1.x + 1, p1.y);
            p3 = sf::Vector2f(p1.x + 1, p1.y - 1);
            tetramino::r_phase = 3;
        }
        else if(tetramino::r_phase == 3)
        {
            p0 = sf::Vector2f(p1.x, p1.y - 1);
            p2 = sf::Vector2f(p1.x, p1.y + 1);
            p3 = sf::Vector2f(p1.x + 1, p1.y + 1);
            tetramino::r_phase = 0;
        }
    }

   
    //checks if any parts of the tetris block thing are out of bounds
    //REMINDER: add block collision here as well
    if
    (
        p0.x > (grid[0].size()-2) || p0.x < 1 || p0.y > grid.size()-2 || p0.y < 0 ||
        p2.x > (grid[0].size()-2) || p2.x < 1 || p2.y > grid.size()-2 || p2.y < 0 ||
        p3.x > (grid[0].size()-2) || p3.x < 1 || p3.y > grid.size()-2 || p3.y < 0 ||
        p1.x > (grid[0].size()-2) || p1.x < 1 || p1.y > grid.size()-2 || p1.y < 0
    )
    {
        tetramino::parts[0] = backup0;
        tetramino::parts[1] = backup1;
        tetramino::parts[2] = backup2;
        tetramino::parts[3] = backup3;
        tetramino::r_phase = backupr;
    }
    else
    {
        tetramino::parts[0] = p0;
        tetramino::parts[2] = p2;
        tetramino::parts[3] = p3;
    }

}
void tetramino::shed()
{
    
}
void tetramino::move(int posx, int posy)
{
    float oldx = parts[1].x;
    float oldy = parts[1].y;

    float x = posx - oldx;
    float y = posy - oldy;

    for(int i = 0; i < parts.size(); i++)
    {
        parts[i].x += x;
        parts[i].y += y;
    }
}
sf::Vector2f tetramino::getPos()
{
    sf::Vector2f pos;
    pos.x = parts[1].x;
    pos.y = parts[1].y;
    return pos;
}