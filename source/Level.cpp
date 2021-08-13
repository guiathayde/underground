#include "Level.h"
#include "GraphicManager.h"
#include "ColliderManager.h"
#include "Item.h"

Level::Level(GraphicManager *graphicManager, ColliderManager *colliderManager) : graphicManager(graphicManager), colliderManager(colliderManager)
{
  entities = new DynamicEntityList();
}

Level::~Level()
{
  ClearAll();
}

void Level::Update(float deltaTime)
{
  list<Character *>::iterator it;
  for (it = characters.begin(); it != characters.end(); ++it)
    (*it)->Update(deltaTime, playerOne);

  list<Item *>::iterator itItem;
  for (itItem = items.begin(); itItem != items.end(); itItem++)
    if ((*itItem)->GetCaught() && (*itItem)->GetStair())
      (*itItem)->SetPosition(sf::Vector2f(
          graphicManager->GetView()->getCenter().x + (graphicManager->GetView()->getSize().x / 2.0f) - (*itItem)->GetHalfSize().x - 20.0f,
          graphicManager->GetView()->getCenter().y - (graphicManager->GetView()->getSize().y / 2.0f) + (*itItem)->GetHalfSize().y + 20.0f));
}

void Level::CheckCollison()
{
  colliderManager->CheckEntitiesCollison(entities, platforms, characters);
  colliderManager->CheckPlayerOnHead(characters, playerOne, NULL);
  colliderManager->CheckItemCollision(items, playerOne, NULL);
}

void Level::Draw(sf::RenderWindow &window)
{
  window.draw(background);
  entities->DrawEntities(window);
}

void Level::ClearAll()
{
  entities->DeleteEntities();
}
