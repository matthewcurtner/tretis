#include <SFML/Graphics.hpp>
#include <vector>
class block
{
  protected:
    float size;
    std::vector<sf::RectangleShape> cubes;
  public:
    float getSize();
    void setSize(float size);
    void drawCubes(sf::RenderWindow& window);
    void setColor(sf::Color color, sf::Color outline);
    void teleport(float posx, float posy);

    block();
};
