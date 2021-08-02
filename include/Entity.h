#pragma once

#include <SFML/Graphics.hpp>
#include "ManagerCollider.h"

class Entity
{
protected:
    
    sf::RectangleShape body;
    bool isPlatform;
public:

    Entity(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, bool isPlatform);
    virtual ~Entity();

    void SetIsPlatfrom(bool b){isPlatform = b;}
    bool IsPlatform(){return  isPlatform;};

    void Drawn(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual ManagerCollider GetManagerCollider() = 0;
};

