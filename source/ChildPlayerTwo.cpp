#include "ChildPlayerTwo.h"

ChildPlayerTwo::ChildPlayerTwo(GraphicManager* graphicManager, sf::Vector2f position)
:Player(graphicManager, texture,size,position,imageCount,switchTime,speed,jumpHeight,ID_PLAYER_TWO,hearts,isAlive,isPlayer,isPlayerOne)
{
    id = ID_PLAYER_TWO;
    size = CHILD_PLAYER_SIZE;
    imageCount = CHILD_PLAYER_IMAGE_COUNT;
    switchTime = CHILD_PLAYER_SWITCH_TIME;
    speed = CHILD_PLAYER_SPEED;
    jumpHeight = CHILD_PLAYER_JUMP_HEIGHT;
    hearts = CHILD_PLAYER_HEARTS;
    
    isAlive = true;
    isPlayer = true;
    isPlayerOne = true;
    
    texture = graphicManager->GetTexture("playerTwo");
    animation = new Animation(texture,imageCount,switchTime);

    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position.x, position.y);
    body.setTexture(texture);
}

ChildPlayerTwo::~ChildPlayerTwo(){

}


void ChildPlayerTwo::Update(float deltaTime, Character *ini)
{

  velocity.x *= 0.5f; // time to stop action walk (slow down)
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    velocity.x -= speed;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    velocity.x += speed;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
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