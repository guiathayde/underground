#pragma once

#include <list>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Platform.h"
#include "Player.h"
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
  Level(int level, sf::View *view);
  ~Level();

  virtual void Initialize(sf::RenderWindow &window, map<const char *, sf::Texture *> *textures) = 0;
  void CheckCollison();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
  Player *GetPlayer() { return static_cast<Player *>(characters.GetPlayer()); }
  void SetPlayer(Player *p) { playerOne = p; };
  void ClearAll();
  float GetSizeX() { return sizeX; }
};
