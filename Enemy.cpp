#include "Enemy.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;


Enemy::Enemy(sf::Texture *texture, sf::Vector2u imageCount,sf::Vector2f origin, float switchTime, float speed,float jumoHeight):Character(texture,imageCount,origin,switchTime,speed,jumpHeight)
{
  body.setSize(sf::Vector2f(100.0f, 150.0f));
  body.setOrigin(body.getSize() / 2.0f);
  body.setPosition(origin.x, origin.y);
  body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, Player p)
{
    
    velocity.x *= 0.5f; // time to stop action walk (slow down)
    if(SeePlayer(p)){
        velocity.x = Attack(p);
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

    
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

bool Enemy::SeePlayer(Player p){
    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p.GetPosition();
    float D = sqrt((pos_player.x-pos_enemy.x)*(pos_player.x-pos_enemy.x)+(pos_player.y-pos_enemy.y)*(pos_player.y-pos_enemy.y));
    
    if(D <= 200)
        return true;
    else 
        return false;
    
}
float Enemy::Attack(Player p){
    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p.GetPosition();

    if(pos_player.x < pos_enemy.x){
        velocity.x -= speed;
        return velocity.x;
    }
    else if(pos_player.x > pos_enemy.x){
        velocity.x += speed;
        return velocity.x;
    }
    return 0.0;
}