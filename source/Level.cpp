#include "Level.h"
#include "GraphicManager.h"
#include "ColliderManager.h"

Level::Level(GraphicManager *graphicManager, ColliderManager *colliderManager)
    : graphicManager(graphicManager), colliderManager(colliderManager)
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
}

void Level::CheckCollison()
{
  colliderManager->CheckEntitiesCollison(entities, platforms, characters);
  colliderManager->CheckPlayerOnHead(characters, playerOne, NULL);
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
