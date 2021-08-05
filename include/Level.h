#pragma once

#include "stdfx.h"

#include "CharacterList.h"
#include "EntityList.h"

class Level
{
protected:
  int level;
  int n_entities;

  EntityList entities;
  CharacterList characters;

  sf::RectangleShape background;

  sf::View *view;
  float sizeX;

  Player *playerOne;

public:
  Level();
  ~Level();

  virtual void Initialize() = 0;
  void CheckCollison();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
  Player *GetPlayer();
  void SetPlayer(Player *p) { playerOne = p; };
  void ClearAll();
  virtual float GetSizeX() { return sizeX; }
};
