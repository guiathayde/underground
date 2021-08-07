#pragma once

#include "stdfix.h"
#include "Entity.h"

class DynamicEntity : public Entity
{
protected:
    sf::RectangleShape body;
    bool isObstacle;

public:
    DynamicEntity(bool isObstacle);

    virtual ~DynamicEntity();

    virtual void Draw(sf::RenderWindow &window) = 0;

    virtual void OnCollision(sf::Vector2f direction) = 0;
};
