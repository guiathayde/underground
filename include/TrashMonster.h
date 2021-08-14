#pragma once
#include "Enemy.h"
#include "Projectile.h"

#define TRASH_MONSTER_SIZE {200.0f,200.0f}
#define TRASH_MONSTER_IMAGECOUNT {6, 2}
#define TRASH_MONSTER_SPEED 100.0f
#define TRASH_MONSTER_JUMP_HEIGHT 200.0f
#define TRASH_MONSTER_HEARTS 200
#define TRASH_MONSTER_SWITCHTIME 0.3f
#define TRASH_MONSTER_TOTAL_STUN_TIME 7.0f

class TrashMonster:public Enemy
{
private:

    int ammunition;

public:

    TrashMonster(GraphicManager* graphicManager,sf::Vector2f origin);
    ~TrashMonster();

    void Update(float deltaTime,Character* character);
    float Attack(Player *p);
    bool SeePlayer(Player *p);
    void Shoot();

};
