#include "tetramino.cpp"
#include <random>

//TODO MAKE FUNCTION THAT SPAWNS THE RANDOM SHAPES

const int SIZE = 40; //the size of each cube
std::vector<std::vector<int>> draw(tetramino tet, std::vector<std::vector<int>> grid)
{
    for(int y = 0; y < grid.size(); y++)
    {
        for(int x = 0; x < grid[y].size(); x++)
        {
            if(grid[y][x] == 1)
            {
                grid[y][x] = 0;
            }
        }
    }
    for(int y = 0; y < grid.size(); y++)
    {
        grid[y][0] = 3;
        grid[y][ (grid[y].size()-1)] = 3;
    }
    for(int i = 0; i < grid[grid.size()-1].size(); i++)
    {
        grid[grid.size()-1][i] = 3;
    }
    for(int i = 0; i < tet.parts.size(); i++)
    {
        grid[tet.parts[i].y][tet.parts[i].x] = 1;
    }
    return grid;
}
std::vector<std::vector<int>> shed(std::vector<std::vector<int>> grid)
{
    for(int y = 0; y < grid.size(); y++)
    {
        for(int x = 0; x < grid[y].size(); x++)
        {
            if(grid[y][x] == 1)
            {
                grid[y][x] = 2;
            }
        }
    }
    return grid;
}
void visualize(sf::RenderWindow& window, std::vector<std::vector<int>> grid, tetramino shape, std::vector<std::vector<sf::RectangleShape>>& squares)
{
    for(int y = 0; y < grid.size(); y++)
    {
        for(int x = 0; x < grid[y].size(); x++)
        {
            squares[y][x].setOutlineColor(sf::Color::Black);

            if(grid[y][x] == 1)
            {
                squares[y][x].setFillColor(sf::Color::Cyan);
                squares[y][x].setOutlineThickness(-1);
            }
            else if(grid[y][x] == 2)
            {
                squares[y][x].setFillColor(sf::Color::Red);
                squares[y][x].setOutlineThickness(-1);
            }
            else if(grid[y][x] == 3)
            {
                squares[y][x].setFillColor(sf::Color::Black);
                squares[y][x].setOutlineThickness(-1);
            }
            else
            {
                squares[y][x].setFillColor(sf::Color::White);
                squares[y][x].setOutlineThickness(0);
            }
        }
    }
    for(int y = 0; y < grid.size(); y++)
    {
        for(int x = 0; x < grid[y].size(); x++)
        {
            window.draw(squares[y][x]);
        }
    }
}
char shapeGen()
{
    char t;
    int wandum = rand() % 7;

    switch (wandum)
    {
    case 0:
        t = 'L';    
        break;
    case 1:
        t = 'J';
        break;
    case 2:
        t = 'T';
        break;
    case 3:
        t = 'O';
        break;
    case 4:
        t = 'S';
        break;
    case 5:
        t = 'Z';
        break;
    case 6:
        t = 'I';
        break;
    default:
        t = 'I';
        break;
    }
    return t;
}