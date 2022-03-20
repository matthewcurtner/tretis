#include "functions.cpp"
int main()
{
    //flags
    bool can_spawn = 1;
    //clocks
    sf::Clock fall_timer;
    sf::Clock rotate_timer;
    //Grid, 0 means nothing 1 means there is a block there.
    std::vector<std::vector<int>> grid;
    grid.resize(24);
    for(int y = 0; y < grid.size();y++)
    {
        grid[y].resize(12);
        for(int  x = 0; x < grid[y].size(); x++)
        {
            grid[y][x] = 0;
        }

        for(int i = 0; i < grid[grid.size()-1].size(); i++)
        {
            grid[grid.size()-1][i] = 3;
        }
    }
    sf::RenderWindow window(sf::VideoMode(960, 960), "Tetris", sf::Style::Resize | sf::Style::Close);

    window.setFramerateLimit(600);
    //tetramino
    tetramino shape;
    for(int HII = 0; window.isOpen(); HII++)
    {
        std::cout << "\n";
        window.clear();
        if(can_spawn)
        {
            shape.falling = 1;
            shape.form('L');
            grid = draw(shape,grid);
            fall_timer.restart();
            can_spawn = false;
        }
        //input
        
        //falling
        if(shape.falling)
        {
            shape.rotate();
        }
        if(fall_timer.getElapsedTime() > sf::seconds(1) && shape.falling)
        {
            std::cout << "fall";
            shape.move(shape.getPos().x, shape.getPos().y + 1);
            fall_timer.restart();
        }
        grid = draw(shape,grid);
        //check if the block should keep falling, put this in the class as a function
        for(int i = 0; i < shape.parts.size(); i++)
        {
            float posx = shape.parts[i].x;
            float posy = shape.parts[i].y;
            if(grid[posy+1][posx] > 1)
            {
                shape.falling = false;
                break;
            }
            else
            {
                shape.falling = true;
            }
        }
        //Print to terminal
        for(int y = 0; y < grid.size();y++)
        {
            std::cout << "\n";
            for(int  x = 0; x < grid[y].size(); x++)
            {
                std::cout << (int)grid[y][x];
            }
        }
    }

    
//idea when the person dies make it say they are mining buttcoin
    
}