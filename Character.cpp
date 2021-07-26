#include <cmath>
#include "Character.h"
#include <list>

Character::Character(sf::Texture *texture, sf::Vector2u imageCount,sf::Vector2f origin ,float switchTime, float speed, float jumpHeight,int hearts, bool isAlive) : animation(texture, imageCount, switchTime)
{
  this->speed = speed;
  this->jumpHeight = jumpHeight;
  this->hearts = hearts;
  this->isAlive = isAlive;
  row = 0;
  faceRight = true;

  
}

Character::~Character()
{
}

void Character::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Character::OnCollision(sf::Vector2f direction)
{
  if (direction.x < 0.0f) // colision on the left
    velocity.x = 0.0f;
  else if (direction.x > 0.0f) // colision on the right
    velocity.x = 0.0f;

  if (direction.y < 0.0f) // collision on the bottom
  {
    velocity.y = 0.0f;
    canJump = true;
  }
  else if (direction.y > 0.0f) // collision on the top
  {
    velocity.y = 0.0f;
  }
}