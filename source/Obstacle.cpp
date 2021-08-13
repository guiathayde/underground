#include "Obstacle.h"

Obstacle::Obstacle(bool isPlatform)
: DynamicEntity(graphicManager,isPlatform)
{
}

Obstacle::~Obstacle()
{
}
void Obstacle::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}

void Obstacle::Update(float deltaTime, Character* character){
    
}