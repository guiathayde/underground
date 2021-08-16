#include "stdfx.h"
#include "Enemy.h"

Enemy::Enemy(GraphicManager *graphicManager, sf::Texture *texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float totalStunTime, int id, int hearts, bool isAlive, bool isPlayer)
    : Character(graphicManager, texture, size, origin, imageCount, switchTime, speed, jumpHeight, id, hearts, isAlive, isPlayer), totalStunTime(totalStunTime)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, Character *character)
{
    Player *p;
    p = static_cast<Player *>(character);

    if (isStunned && coolDown > totalStunTime)
    {
        isStunned = false;
    }
    coolDown += deltaTime;

    velocity.x *= 0.5f; // time to stop action walk (slow down)
    if (!isStunned && SeePlayer(*p))
    {
        coolDown = 0;
        velocity.x = Attack(*p);
    }

    velocity.y += 981.0f * deltaTime;

    if (velocity.x == 0.0f)
        row = 0;
    else
    {
        row = 1;

        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    if (hearts <= 0)
    {
        isAlive = false;
    }

    animation->Update(row, deltaTime, faceRight);
    body.setTextureRect(animation->uvRect);
    body.move(velocity * deltaTime);
}

bool Enemy::SeePlayer(Player p)
{
    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p.GetPosition();
    float D = sqrt((pos_player.x - pos_enemy.x) * (pos_player.x - pos_enemy.x) + (pos_player.y - pos_enemy.y) * (pos_player.y - pos_enemy.y));

    if (D <= 500.0)
        return true;
    else
        return false;
}
float Enemy::Attack(Player p)
{
    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p.GetPosition();

    if (pos_player.x < pos_enemy.x)
    {
        velocity.x -= speed;
        return velocity.x;
    }
    else if (pos_player.x > pos_enemy.x)
    {
        velocity.x += speed;
        return velocity.x;
    }

    return 0.0;
}