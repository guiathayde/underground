#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Character
{
protected:
  sf::RectangleShape body;
  Animation animation;
  unsigned int row;
  float speed;
  bool faceRight;

  sf::Vector2f velocity;
  bool canJump;
  float jumpHeight;

public:
  Character(sf::Texture *texture, sf::Vector2u imageCount, sf::Vector2f origin,float switchTime, float speed, float jumpHeight);
  ~Character();

  virtual void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  Collider GetCollider() { return Collider(body); }
};