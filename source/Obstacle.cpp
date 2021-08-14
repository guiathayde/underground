#include "Obstacle.h"

Obstacle::Obstacle(bool isPlatform,bool isSpike)
: DynamicEntity(graphicManager,isPlatform,false,false)
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