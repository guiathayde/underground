#include "stdfx.h"

#include "ColliderManager.h"
#include "DynamicEntityList.h"
#include "Player.h"
#include "Enemy.h"
#include "Platform.h"
#include "DynamicEntity.h"
#include "Obstacle.h"

ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}

bool ColliderManager::CheckCollision(sf::RectangleShape &body, sf::RectangleShape &otherBody, sf::Vector2f &direction, float push)
{
  sf::Vector2f otherPosition = otherBody.getPosition();
  sf::Vector2f otherHalfSize = otherBody.getSize() / 2.0f;
  sf::Vector2f thisPosition = body.getPosition();
  sf::Vector2f thisHalfSize = body.getSize() / 2.0f;

  float deltaX = otherPosition.x - thisPosition.x;
  float deltaY = otherPosition.y - thisPosition.y;

  float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
  float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

  if (intersectX < 0.0f && intersectY < 0.0f)
  {
    push = std::min(std::max(push, 0.0f), 1.0f);

    if (intersectX > intersectY)
    {
      if (deltaX > 0.0f)
      {
        otherBody.move(-intersectX * push, 0.0f);

        direction.x = 1.0f;
        direction.y = 0.0f;
      }
      else
      {
        otherBody.move(intersectX * push, 0.0f);

        direction.x = -1.0f;
        direction.y = 0.0f;
      }
    }
    else
    {
      if (deltaY > 0.0f)
      {
        otherBody.move(0.0f, -intersectY * push);

        direction.x = 0.0f;
        direction.y = 1.0f;
      }
      else
      {
        otherBody.move(0.0f, intersectY * push);

        direction.x = 0.0f;
        direction.y = -1.0f;
      }
    }

    return true;
  }

  return false;
}

bool ColliderManager::CheckOnHeadCollision(sf::RectangleShape &body, sf::RectangleShape &otherBody)
{
  sf::Vector2f otherPosition = otherBody.getPosition();
  sf::Vector2f otherHalfSize = otherBody.getSize() / 2.0f;
  sf::Vector2f thisPosition = body.getPosition();
  sf::Vector2f thisHalfSize = body.getSize() / 2.0f;

  float deltaY = abs(otherPosition.y - thisPosition.y);
  float xThisBegin = abs(thisPosition.x - thisHalfSize.x);
  float xThisEnd = abs(thisPosition.x + thisHalfSize.x);

  float sizeY = abs(otherHalfSize.y + thisHalfSize.y);
  float copm = deltaY - sizeY;

  if (otherPosition.x >= xThisBegin && otherPosition.x <= xThisEnd && copm <= 0)
    return true;

  else
    return false;
}

void ColliderManager::CheckEntitiesCollison(DynamicEntityList *entities, list<Obstacle *> platforms, list<Character *> characters)
{
  sf::Vector2f direction;
  list<Obstacle *>::iterator itPlatforms;
  list<Character *>::iterator itCharacters;

  for (itPlatforms = platforms.begin(); itPlatforms != platforms.end(); itPlatforms++)
    for (itCharacters = characters.begin(); itCharacters != characters.end(); itCharacters++)
      if (CheckCollision((*(*itPlatforms)->GetBody()), (*(*itCharacters)->GetBody()), direction, 1.0f))
          (*itCharacters)->OnCollision(direction);
  
  for (int i = 0; i < entities->GetSize(); i++)
    for (int j = 0; j < entities->GetSize(); j++)
     if((*entities)[i] && (*entities)[j])
      if (i != j && !(*entities)[i]->GetIsObstacle() && CheckCollision(*((*entities)[i])->GetBody(), *((*entities)[j])->GetBody(), direction, 0.1f))
        (*entities)[j]->OnCollision(direction);
}

void ColliderManager::CheckPlayerOnHead(list<Character *> characters, Player *playerOne, Player *playerTwo)
{
  list<Character *>::iterator itCharacters;

  for (itCharacters = characters.begin(); itCharacters != characters.end(); itCharacters++)
    if (!(*itCharacters)->GetIsPlayer() && CheckOnHeadCollision(*playerOne->GetBody(), (*(*itCharacters)->GetBody()))){
      static_cast<Enemy *>((*itCharacters))->SetStunned();
    }
  if (playerTwo)
    for (itCharacters = characters.begin(); itCharacters != characters.end(); itCharacters++)
      if (!(*itCharacters)->GetIsPlayer() && CheckOnHeadCollision(*playerTwo->GetBody(), (*(*itCharacters)->GetBody())))
        static_cast<Enemy *>((*itCharacters))->SetStunned();
}