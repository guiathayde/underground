#pragma once

#include <SFML/Graphics.hpp>
#include "Collider.h"

class Entity
{
protected:
    
    sf::RectangleShape body;
    bool isPlatform;

public:

    Entity(bool isPlatform);
    virtual ~Entity();

    void SetIsPlatfrom(bool b){isPlatform = b;}
    bool IsPlatform(){return  isPlatform;};

    void Drawn(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;
    Collider GetCollider(){return Collider(body);}
};

