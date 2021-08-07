#pragma once

#include "stdfx.h"
#include "DynamicEntity.h"
#include "Animation.h"
#include "ColliderManager.h"

class Character : public DynamicEntity
{
protected:
  sf::Texture texture;
  sf::Vector2u imageCount;
  sf::Vector2f origin;

  sf::Vector2f velocity;

  Animation animation;

  unsigned int row;
  int hearts;

  float speed;
  float jumpHeight;

  bool canJump;
  bool faceRight;
  bool isAlive;
  bool isPlayer;

public:
  Character(sf::Texture *texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int hearts, bool isAlive, bool isPlayer);
  ~Character();

  virtual void Update(float deltaTime, Character *character) = 0;
  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);
  float getVelocityX() { return velocity.x; }

  sf::Vector2f GetPosition() { return body.getPosition(); }
  ColliderManager GetColliderManager() { return ColliderManager(this->body); }

  bool GetIsAlive() { return isAlive; }
  bool GetIsPlayer() { return isPlayer; }

  void SetIsAlive(bool alive) { isAlive = alive; };
};