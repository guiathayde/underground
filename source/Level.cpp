#include "Level.h"
#include "CharacterList.h"

Level::Level() : entities(n_entities, true)
{
}

Level::~Level()
{
  ClearAll();
}

void Level::CheckCollison()
{
  entities.CheckEntitiesCollision();
}

void Level::Draw(sf::RenderWindow &window)
{
  window.draw(background);
  entities.DrawEntities(window);
}

void Level::Update(float deltaTime)
{
  characters.UpdateCharacter(deltaTime);
}

void Level::ClearAll()
{
  entities.DeleteEntities();
}
Player *Level::GetPlayer()
{
  return static_cast<Player *>(characters.GetPlayer());
}