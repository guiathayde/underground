#pragma once

#include "Entity.h"
class Obstacle:public Entity
{
private:
    
public:
    
    Obstacle(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position,bool IsPlatform);
    virtual ~Obstacle();

    
    void Draw(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual ManagerCollider GetManagerCollider(){return ManagerCollider(body);};

};

