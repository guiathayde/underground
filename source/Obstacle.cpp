#include "Obstacle.h"
 
 Obstacle::Obstacle(bool isPlatform)
 :Entity(isPlatform)
{

}

Obstacle::~Obstacle(){ 
}
void Obstacle::Draw(sf::RenderWindow &window){
    window.draw(body);
}