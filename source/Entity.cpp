#include "Entity.h"

Entity::Entity(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, bool isPlatform)
{
      this->isPlatform = isPlatform;
}


Entity::~Entity(){

}

void Entity::Drawn(sf::RenderWindow &window){
      window.draw(body);
}
