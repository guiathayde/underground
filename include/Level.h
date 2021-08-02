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

  list<Platform *> platforms;
  Player *playerOne;

public:
  Level(int level, sf::Texture backgroundTexture);
  ~Level();

  void Initialize(int enimiesNum);
  void CheckCollison();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
  Player *GetPlayer() { return static_cast<Player*>(characters.GetPlayer()); }
  void SetPlayer(Player *p) { playerOne = p; };
  void ClearAll();
};
