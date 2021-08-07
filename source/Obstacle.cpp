#include "Obstacle.h"

Obstacle::Obstacle(bool isPlatform)
    : DynamicEntity(isPlatform)
{
}

Obstacle::~Obstacle()
{
}
void Obstacle::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}