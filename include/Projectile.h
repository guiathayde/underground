#pragma once

#include "DynamicEntity.h"
#include "Animation.h"
#include "Player.h"


#define PROJECTILE_VELOCITY {300.0f, 0.0f}
#define PROJECTILE_SIZE {100.0f,50.0f}
#define PROJECTILE_IMAGE_COUNT {2,1}
#define PROJECTILE_SWITCH_TIME 0.3F

class Character;
class Projectile: public DynamicEntity
{
private:
    
    sf::Vector2f size;
    sf::Vector2f velocity;
    sf::Vector2f position;
    sf::Vector2u imageCount;

    float time;
    float switchTime;
    float speed;

    int row;
    bool faceRight;



public:
    Projectile(GraphicManager* graphicManager,sf::Vector2f position,float speed);
    ~Projectile();

    void Draw(sf::RenderWindow &window);
    void OnCollision(sf::Vector2f direction);
    void Update(float deltaTime,Character *p);
    
    float Attack(Player *p);

};


