#pragma once

#include "Enemy.h"
#include "Projectile.h"
#include "stdfx.h"
#include "DynamicEntityList.h"

#define WELDER_ENEMY_SIZE {100.0f,100.0f}
#define WELDER_ENEMY_IMAGECOUNT {8, 2}
#define WELDER_ENEMY_SPEED 100.0f
#define WELDER_ENEMY_JUMP_HEIGHT 200.0f
#define WELDER_ENEMY_HEARTS 200
#define WELDER_ENEMY_SWITCHTIME 0.3f
#define WELDER_ENEMY_TOTAL_STUN_TIME 7.0f

class WelderEnemy:public Enemy
{
private:
    DynamicEntityList *entities;
    Projectile *projectile;
    float shootCoolDown;
    int ammunition;
public:

    WelderEnemy(GraphicManager* graphicManager,sf::Vector2f origin,DynamicEntityList *entities);
    ~WelderEnemy();

    void Update(float deltaTime,Character* character);
    float Attack(Player *p);
    bool SeePlayer(Player *p);
    void Shoot();

};
