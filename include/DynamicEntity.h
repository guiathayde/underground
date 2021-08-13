#pragma once

#include "stdfix.h"
#include "Entity.h"
#include "Animation.h"

class Character;
class DynamicEntity : public Entity
{
protected:
    
    
    Animation *animation;

    sf::Texture *texture;
    sf::RectangleShape body;
    bool isObstacle;

public:
    DynamicEntity(GraphicManager* graphicManager,bool isObstacle);
    virtual ~DynamicEntity();

    sf::RectangleShape *GetBody() { return &body; }

    bool GetIsObstacle() { return isObstacle; }
    virtual void Draw(sf::RenderWindow &window) = 0;
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual void Update(float deltaTime, Character* character) = 0;
};
