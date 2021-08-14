#pragma once

#include "stdfx.h"
#include "DynamicEntity.h"

class Obstacle : public DynamicEntity
{
private:
    bool isPlatform;
    bool isSpike;

public:
    Obstacle(bool isPlatform,bool isSpike);
    virtual ~Obstacle();

    void Draw(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual void Update(float deltaTime, Character* character);

    bool GetIsPlatform(){return isPlatform;}
    bool GetIsSpike(){return isSpike;}

};
