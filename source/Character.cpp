#include "Character.h"
Character::Character(GraphicManager *graphicManager, sf::Texture *texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int id, int hearts, bool isAlive, bool isPlayer, bool isEnemy)
    : DynamicEntity(graphicManager, false, false, isPlayer,isEnemy, false)
{
  this->id = id;
  this->speed = speed;
  this->jumpHeight = jumpHeight;
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

void Character::Update(float deltaTime, Character *character)
{
}