#include "Player.h"

Player::Player(GraphicManager* graphicManager, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int hearts, bool isAlive, bool isPlayer, bool isPlayerOne) 
:Character(graphicManager,texture, size, origin, imageCount, switchTime, speed, jumpHeight, hearts, isAlive, isPlayer)
{
  texture = new sf::Texture();
  
  texture = graphicManager->GetTexture("playerOne");
  
  animation = new Animation(texture,imageCount,switchTime);

  this->isPlayerOne = isPlayerOne;
  this->isPlayer = isPlayer;
  body.setSize(sf::Vector2f(60.0f, 70.0f));
  body.setOrigin(body.getSize() / 2.0f);
  body.setPosition(origin.x, origin.y);
  body.setTexture(texture);
  
  //cout << "Saiu da construtora de player" <<endl;


}

Player::~Player()
{
  cout << "Entrou na destrutora do player"<< endl;
  delete(texture);
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

  animation->Update(row, deltaTime, faceRight);
  body.setTextureRect(animation->uvRect);
  body.move(velocity * deltaTime);
}

void Player::GetDamage()
{
  this->hearts--;
}
