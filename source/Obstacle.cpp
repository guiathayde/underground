#include "Obstacle.h"
 
 Obstacle::Obstacle(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position,bool isPlatform)
 :Entity(texture,size,position,isPlatform)
{

}

Obstacle::~Obstacle(){
}
void Obstacle::Draw(sf::RenderWindow &window){
    window.draw(body);
}