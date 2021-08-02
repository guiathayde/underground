#pragma once

#include <list>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Platform.h"
#include "Player.h"
#include "CharacterList.h"
#include "List.h"

class Level
{
private:
  int level;
  float sizeX;

  sf::Texture backgroundTexture;
  sf::Texture platformTexture;
  sf::RectangleShape background;
  sf::View *view;

  CharacterList characters;

  list<Enemy *> enemies;
  list<Platform *> platforms;
  Player *playerOne;

public:
  Level(int level, sf::Texture backgroundTexture, sf::View *view, float sizeX);
  ~Level();

  void Initialize(int enimiesNum, sf::RenderWindow &window);
  void CheckCollison();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);

  float GetSizeX() { return sizeX / 2.0f; }

  Player *GetPlayer() { return static_cast<Player *>(characters.GetPlayer()); }
  void SetPlayer(Player *p) { playerOne = p; };
};
