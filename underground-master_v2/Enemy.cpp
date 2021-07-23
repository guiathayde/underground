#include "Enemy.h"

Enemy::Enemy(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime)
{
  this->speed = speed;
  row = 0;
  faceRight = true;

  body.setSize(sf::Vector2f(100.0f, 150.0f));
  body.setPosition(200.0f, 200.0f);
  body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
  sf::Vector2f movment(0.0f, 0.0f);

  if(movment.x < 1000.0f)
    movment.x += speed * deltaTime; 
  else
    
  if (movment.x == 0.0f)
    row = 0;
  else
  {
    row = 1;

    if (movment.x > 0.0f)
      faceRight = true;
    else
      faceRight = false;
  }

  animation.Update(row, deltaTime, faceRight);
  body.setTextureRect(animation.uvRect);
  body.move(movment);
}

void Enemy::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}