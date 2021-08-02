#pragma once

#include "Entity.h"
#include <iostream>
using std::cout;
using std::endl;

class Obstacle:public Entity
{
private:
    bool isPlatform;

public:
    
    Obstacle(bool isPlatform);
    virtual ~Obstacle();

    
    void Draw(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual Collider GetCollider(){return Collider(body);};

};

