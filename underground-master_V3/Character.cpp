#include <cmath>
#include "Character.h"

Character::Character(sf::Texture *texture, sf::Vector2u imageCount,sf::Vector2f origin ,float switchTime, float speed, float jumpHeight) : animation(texture, imageCount, switchTime)
{
  this->speed = speed;
  this->jumpHeight = jumpHeight;
  row = 0;
  faceRight = true;

  body.setSize(sf::Vector2f(100.0f, 150.0f));
  body.setOrigin(body.getSize() / 2.0f);
  body.setPosition(origin.x, origin.y);
  body.setTexture(texture);
}

Character::~Character()
{
}

void Character::Update(float deltaTime)
{
    
  
    velocity.y += 981.0f * deltaTime;
    
    
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
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