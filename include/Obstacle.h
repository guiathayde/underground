#pragma once

#include "stdfx.h"
#include "DynamicEntity.h"

class Obstacle : public DynamicEntity
{
private:
    bool isPlatform;

public:
    Obstacle(bool isPlatform);
    virtual ~Obstacle();

    void Draw(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;

};
