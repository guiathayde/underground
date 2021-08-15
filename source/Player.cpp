#include "Player.h"

Player::Player(GraphicManager* graphicManager,sf::Texture *texture ,sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight,int id ,int hearts, bool isAlive, bool isPlayer, bool isPlayerOne) 
:Character(graphicManager,texture, size, origin, imageCount, switchTime, speed, jumpHeight, id, hearts, isAlive, isPlayer)
{
  this->id = 0;
  this->isPlayerOne = isPlayerOne;
  this->isPlayer = isPlayer;
}

Player::~Player()
{
  cout << "Entrou na destrutora do player"<< endl;
}

void Player::Update(float deltaTime, Character *ini)
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

  if (velocity.y < 0)
    row = 2;
  else if (velocity.y > 0 && !canJump)
    row = 3;

  if (hearts <= 0)
    isAlive = false;
  //cout << hearts <<endl;

  animation->Update(row, deltaTime, faceRight);
  body.setTextureRect(animation->uvRect);
  body.move(velocity * deltaTime);
}