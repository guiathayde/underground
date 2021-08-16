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

    bool isEnemy;
    bool isObstacle;
    bool isProjectile;
    bool isPlayer;
    bool isItem;

public:
    DynamicEntity(GraphicManager* graphicManager,bool isObstacle,bool isProjectile, bool isPlayer,bool isEnemy, bool isItem);
    virtual ~DynamicEntity();

    sf::RectangleShape *GetBody() { return &body; }

    bool GetIsObstacle() { return isObstacle; }
    bool GetIsProjectile(){return isProjectile;}
    bool GetIsPlayer(){return isPlayer;}
    bool GetIsItem(){return isItem;}
    bool GetIsEnemy(){return isEnemy;}
    virtual void Draw(sf::RenderWindow &window) = 0;
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual void Update(float deltaTime, Character* character) = 0;
};
