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
    if(type == 'J')
    {
        tetramino::type = 'J';
        parts[0].x = 5;
        parts[0].y = 0;
        parts[1].x = 5;
        parts[1].y = 1;
        parts[2].x = 5;
        parts[2].y = 2;
        parts[3].x = 4;
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
void tetramino::rotate(std::vector<std::vector<int>> grid)
{
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
    if(tetramino::type == 'J')
    {
        
        if(tetramino::r_phase == 0)
        {
            p0 = sf::Vector2f(p1.x + 1, p1.y);
            p2 = sf::Vector2f(p1.x - 1, p1.y);
            p3 = sf::Vector2f(p1.x - 1, p1.y - 1);
            tetramino::r_phase = 1;
        }
        else if(tetramino::r_phase == 1)
        {
            p0 = sf::Vector2f(p1.x, p1.y + 1);
            p2 = sf::Vector2f(p1.x, p1.y - 1);
            p3 = sf::Vector2f(p1.x + 1, p1.y - 1);  
            tetramino::r_phase = 2;
        }
        else if(tetramino::r_phase == 2)
        {
            p0 = sf::Vector2f(p1.x - 1, p1.y);
            p2 = sf::Vector2f(p1.x + 1, p1.y);
            p3 = sf::Vector2f(p1.x + 1, p1.y + 1);
            tetramino::r_phase = 3;
        }
        else if(tetramino::r_phase == 3)
        {
            p0 = sf::Vector2f(p1.x, p1.y - 1);
            p2 = sf::Vector2f(p1.x, p1.y + 1);
            p3 = sf::Vector2f(p1.x - 1, p1.y + 1);
            tetramino::r_phase = 0;
        }
        
    }

   
    //checks if any parts of the tetris block thing are clipping through bounds
    if
    (
        p0.x > (grid[0].size()-2) || p0.x < 1 || p0.y > grid.size()-2 || p0.y < 0 ||
        p2.x > (grid[0].size()-2) || p2.x < 1 || p2.y > grid.size()-2 || p2.y < 0 ||
        p3.x > (grid[0].size()-2) || p3.x < 1 || p3.y > grid.size()-2 || p3.y < 0 ||
        p1.x > (grid[0].size()-2) || p1.x < 1 || p1.y > grid.size()-2 || p1.y < 0 || 
        grid[p0.y][p0.x] > 1 || grid[p1.y][p1.x] > 1 || grid[p2.y][p2.x] > 1 || grid[p3.y][p3.x] > 1 
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
        tetramino::parts[1] = p1;
        tetramino::parts[2] = p2;
        tetramino::parts[3] = p3;
    }

}

void tetramino::move(int posx, int posy, std::vector<std::vector<int>> grid)
{
    sf::Vector2f backup0 = tetramino::parts[0];
    sf::Vector2f backup1 = tetramino::parts[1];
    sf::Vector2f backup2 = tetramino::parts[2];
    sf::Vector2f backup3 = tetramino::parts[3];

    float oldx = parts[1].x;
    float oldy = parts[1].y;

    float x = posx - oldx;
    float y = posy - oldy;

    sf::Vector2f p0 = tetramino::parts[0];
    sf::Vector2f p1 = tetramino::parts[1];
    sf::Vector2f p2 = tetramino::parts[2];
    sf::Vector2f p3 = tetramino::parts[3];

    p0.x += x;
    p0.y += y;
    p1.x += x;
    p1.y += y;
    p2.x += x;
    p2.y += y;
    p3.x += x;
    p3.y += y;
    
    if
    (
        p0.x > (grid[0].size()-2) || p0.x < 1 || p0.y > grid.size()-2 || p0.y < 0 ||
        p2.x > (grid[0].size()-2) || p2.x < 1 || p2.y > grid.size()-2 || p2.y < 0 ||
        p3.x > (grid[0].size()-2) || p3.x < 1 || p3.y > grid.size()-2 || p3.y < 0 ||
        p1.x > (grid[0].size()-2) || p1.x < 1 || p1.y > grid.size()-2 || p1.y < 0 || 
        grid[p0.y][p0.x] > 1 || grid[p1.y][p1.x] > 1 || grid[p2.y][p2.x] > 1 || grid[p3.y][p3.x] > 1 
    )
    {
        tetramino::parts[0] = backup0;
        tetramino::parts[1] = backup1;
        tetramino::parts[2] = backup2;
        tetramino::parts[3] = backup3;
    }
    else
    {
        tetramino::parts[0] = p0;
        tetramino::parts[1] = p1;
        tetramino::parts[2] = p2;
        tetramino::parts[3] = p3;
    }
}
sf::Vector2f tetramino::getPos()
{
    sf::Vector2f pos;
    pos.x = parts[1].x;
    pos.y = parts[1].y;
    return pos;
}