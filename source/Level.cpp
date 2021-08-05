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
  entities.CheckEntitysCollision();
}

void Level::Draw(sf::RenderWindow &window)
{
  window.draw(background);
  entities.DrawEntitys(window);
}

void Level::Update(float deltaTime)
{
  characters.UpdateCharacter(deltaTime);
}

void Level::ClearAll()
{
  entities.DeleteEntitys();
}
Player *Level::GetPlayer()
{ return static_cast<Player *>(characters.GetPlayer()); }