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
private:
  
  int level;
  int n_entities;

  sf::Texture backgroundTexture;
  sf::Texture platformTexture;

  EntityList entities;
  CharacterList characters;

  sf::RectangleShape background;

  sf::View *view;
  float sizeX;

  Player *playerOne;

public:
  Level(int level, sf::Texture backgroundTexture, sf::View *view, float sizeX);
  ~Level();

  void Initialize(int enimiesNum, sf::RenderWindow &window);
  void CheckCollison();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
  Player *GetPlayer() { return static_cast<Player*>(characters.GetPlayer()); }
  void SetPlayer(Player *p) { playerOne = p; };
  void ClearAll();
  float GetSizeX() { return sizeX / 2.0f; }
};
