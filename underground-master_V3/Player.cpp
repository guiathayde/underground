#include <cmath>
#include "Player.h"

Player::Player(sf::Texture *texture, sf::Vector2u imageCount,sf::Vector2f origin, float switchTime, float speed, float jumpHeight,bool isPlayerOne):Character(texture,imageCount,origin,switchTime,speed,jumpHeight) 
{
  
  this->isPlayerOne = isPlayerOne;


}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
  velocity.x *= 0.5f; // time to stop action walk (slow down)

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    velocity.x -= speed;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    velocity.x += speed;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
  {
    canJump = false;

    // kinematic equation of jump https://www.youtube.com/watch?v=v1V3T5BPd7E
    velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
  }

  // gravity
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