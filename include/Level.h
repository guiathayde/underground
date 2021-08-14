#pragma once

#include "stdfx.h"
#include "Player.h"
#include "DynamicEntityList.h"
#include "Obstacle.h"

class Item;
class GraphicManager;
class ColliderManager;
class Ranking;
class Level : public Entity
{
protected:
  int n_entities;
  int score;
  int nextLevel;
  bool endLevel;

  string nameLevel;
  string name;

  sf::Font font;
  sf::Text scoreText[2];
  sf::Text endLevelText[5];

  DynamicEntityList *entities;
  list<Character *> characters;
  list<Obstacle *> platforms;
  list<Item *> items;

  Player *playerOne;
  Player *playerTwo;

  ColliderManager *colliderManager;
  GraphicManager *graphicManager;

  sf::RectangleShape background;
  sf::RectangleShape endLevelBackground;

  float sizeX;

public:
  Level(GraphicManager *graphicManager, ColliderManager *colliderManager);
  virtual ~Level();

  virtual void Initialize() = 0;
  virtual void InitializeCharacters() = 0;

  void SetEndLevel(sf::Event event);
  int SetContinueLevel(sf::Event event, Ranking *ranking);

  void Update(float deltaTime);
  void CheckCollison();
  void Draw(sf::RenderWindow &window);

  list<Character *> *GetListCharacters() { return &characters; }

  string GetNameLevel() { return nameLevel; }

  int GetScore() { return score; }
  bool GetEndLevel() { return endLevel; }

  Player *GetPlayer() { return playerOne; };
  void SetPlayerOne(Player *p) { playerOne = p; };
  void SetPlayerTwo(Player *p) { playerTwo = p; };

  void ClearAll();

  virtual float GetSizeX() { return sizeX; }
};
