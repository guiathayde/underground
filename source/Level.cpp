#include "Level.h"

Level::Level(int level, sf::View *view) : entities(n_entities, true)
{
  this->level = level;
  this->view = view;
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