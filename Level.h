#pragma once

#include <list>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Platform.h"
#include "Player.h"

class Level
{
private:
  int level;

  sf::Texture backgroundTexture;
  sf::Texture platformTexture;

  list<Enemy *> enemies;
  list<Platform *> platforms;
  Player *playerOne;

public:
  Level(int level, sf::Texture backgroundTexture);
  ~Level();

  void Initialize(int enimiesNum);
  void CheckCollison();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
  Player GetPlayer() { return *playerOne; }
  void SetPlayer(Player *p) { playerOne = p; };
};
