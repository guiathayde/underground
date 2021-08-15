#pragma once

#include "stdfx.h"
#include "DynamicEntity.h"

class Obstacle : public DynamicEntity
{
private:
    int id;

    bool isPlatform;
    bool isSpike;

public:
    Obstacle(int id,bool isPlatform,bool isSpike);
    virtual ~Obstacle();

    void Draw(sf::RenderWindow &window);
    virtual void OnCollision(sf::Vector2f direction) = 0;
    virtual void Update(float deltaTime, Character* character);

    bool GetIsPlatform() { return isPlatform; }
    bool GetIsSpike() { return isSpike; }

    int GetId() { return id; }
    sf::Vector2f GetPosition() { return body.getPosition(); }
};
