#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
class Character
{
protected:
  sf::RectangleShape body;
  sf::Texture texture;
  sf::Vector2u imageCount;
  sf::Vector2f origin;
  sf::Vector2f velocity;

  Animation animation;

  unsigned int row;
  int hearts;

  float switchTime;
  float speed;
  float jumpHeight;

  bool canJump;
  bool faceRight;
  bool isAlive;
  bool isPlayer;

public:
  Character(sf::Texture *texture, sf::Vector2u imageCount, sf::Vector2f origin, float switchTime, float speed, float jumpHeight, int hearts, bool isAlive, bool isPlayer);
  ~Character();

  virtual void Update(float deltaTime, Character *character) = 0;
  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);
  float getVelocityX() { return velocity.x; }

  sf::Vector2f GetPosition() { return body.getPosition(); }
  Collider GetCollider() { return Collider(body); }
  bool GetIsAlive() { return isAlive; }
  bool GetIsPlayer() { return isPlayer; }
  void SetIsAlive(bool alive) { isAlive = isAlive; };
};