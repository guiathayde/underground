#include "Entity.h"

Entity::Entity(bool isPlatform)
{
      this->isPlatform = isPlatform;
}


Entity::~Entity(){

}

void Entity::Drawn(sf::RenderWindow &window){
      window.draw(body);
}
