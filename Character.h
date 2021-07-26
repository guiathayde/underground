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

  Animation animation;
  unsigned int row;
  float switchTime;
  float speed;
  bool faceRight;

  sf::Vector2f velocity;
  bool canJump;
  float jumpHeight;

public:
  Character(sf::Texture *texture, sf::Vector2u imageCount, sf::Vector2f origin,float switchTime, float speed, float jumpHeight);
  ~Character();

  //virtual void Update(float deltaTime) = 0;
  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);
  float getVelocityX(){return velocity.x;}

  sf::Vector2f GetPosition() { return body.getPosition(); }
  Collider GetCollider() { return Collider(body); }
};