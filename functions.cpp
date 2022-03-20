#include "tetramino.cpp"
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