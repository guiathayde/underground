#pragma once

#include "Enemy.h"
#include "stdfx.h"

#define HOLLOW_HAT_ENEMY_SIZE {100.0f,100.0f}
#define HOLLOW_HAT_ENEMY_IMAGECOUNT {6, 2}
#define HOLLOW_HAT_ENEMY_SPEED 100.0f
#define HOLLOW_HAT_ENEMY_JUMP_HEIGHT 200.0f
#define HOLLOW_HAT_ENEMY_HEARTS 200
#define HOLLOW_HAT_ENEMY_SWITCHTIME 0.3f
#define HOLLOW_HAT_ENEMY_TOTAL_STUN_TIME 7.0f


class HollowHatEnemy:public Enemy
{
private:

public:
    
    HollowHatEnemy(GraphicManager* graphicManager,sf::Vector2f origin);
    ~HollowHatEnemy();

    void Update(float deltaTime,Character* character);
    float Attack(Player *p);
    bool SeePlayer(Player *p);

};

