#pragma once

#include "stdfx.h"
#include "DynamicEntity.h"
#include "Animation.h"

class Character : public DynamicEntity
{
protected:
  
  
  sf::Texture* texture;

  sf::Vector2f origin;
  sf::Vector2f velocity;
  sf::Vector2f size;
  sf::Vector2u imageCount;
  
  
  int hearts;

  float speed;
  float jumpHeight;
  float switchTime;
  

  unsigned int row;

  bool canJump;
  bool faceRight;
  bool isAlive;
  bool isPlayer;

public:
  Character(GraphicManager* graphicManager,sf::Texture* texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int hearts, bool isAlive, bool isPlayer);
  ~Character();

  virtual void Update(float deltaTime, Character *character);
  void Draw(sf::RenderWindow &window);
  float getVelocityX() { return velocity.x; }
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }

  bool GetIsAlive() { return isAlive; }
  bool GetIsPlayer() { return isPlayer; }

  void SetIsAlive(bool alive) { isAlive = alive; };
};