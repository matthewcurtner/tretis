#include "functions.cpp"
int main()
{
    //flags
    bool can_spawn = 1;
    //clocks
    sf::Clock fall_timer;
    sf::Clock rotate_timer;
    sf::Clock move_timer;
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
    //2d version of the other grid
    std::vector<std::vector<sf::RectangleShape>> squares;
    squares.resize(24);
    for(int y = 0; y < squares.size(); y++)
    {
        squares[y].resize(12);
        for(int x = 0; x < squares[y].size(); x++)
        {
            squares[y][x].setSize(sf::Vector2f(SIZE,SIZE));
            
        }
    }
    for(int y = 0; y < squares.size(); y++)
    {
        for(int x = 0; x < squares[y].size(); x++)
        {
            squares[y][x].setPosition(sf::Vector2f(SIZE * x, SIZE * y));
            squares[y][x].setFillColor(sf::Color::White);
        }
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tetris", sf::Style::Resize | sf::Style::Close);

    window.setFramerateLimit(60);
    //tetramino
    tetramino shape;
    for(int HII = 0; window.isOpen(); HII++)
    {
        std::cout << "\n";
        window.clear();
        if(can_spawn)
        {
            shape.falling = 1;
            //make this pick a random shape
            shape.form(shapeGen());
            grid = draw(shape,grid);
            fall_timer.restart();
            can_spawn = false;
        }
        //input REMINDER: Turn this into a function
        //rotating
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rotate_timer.getElapsedTime() > sf::seconds(.1))
        {
            shape.rotate(grid);
            rotate_timer.restart();
        }
        //left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && move_timer.getElapsedTime() > sf::seconds(.1))
        {
            shape.move(shape.parts[1].x-1,shape.parts[1].y, grid);
            move_timer.restart();
        }
        //right
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && move_timer.getElapsedTime() > sf::seconds(.1))
        {
            shape.move(shape.parts[1].x+1,shape.parts[1].y, grid);
            move_timer.restart();
        }

        //falling
        if(fall_timer.getElapsedTime() > sf::seconds(1) && shape.falling)
        {
            shape.move(shape.getPos().x, shape.getPos().y + 1, grid);
            fall_timer.restart();
        }
        grid = draw(shape,grid);
        
        //checks whether the block should keep falling
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
        //checks if the shape is done moving (the timer allows the player to move the shape for a certain amount of time before it stops)
        if(!shape.falling && fall_timer.getElapsedTime() > sf::seconds(2))
        {
            grid = shed(grid);
            can_spawn = true;
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
        //print to screen
        visualize(window, grid, shape, squares);
 
        window.display();
    }

    

    
}