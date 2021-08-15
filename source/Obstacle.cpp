#include "Obstacle.h"

Obstacle::Obstacle(int id,bool isPlatform,bool isSpike)
: DynamicEntity(graphicManager,isPlatform,true,false,false)
{
    this->isSpike = isSpike;
    this->id = id;
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