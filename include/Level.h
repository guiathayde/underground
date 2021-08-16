#pragma once

#include "stdfx.h"

#include "Entity.h"
#include "DynamicEntityList.h"
#include "Character.h"
#include "ColliderManager.h"

class Player;
class Obstacle;
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
  int hearts;

  bool isCoop;
  bool isStairCought;
  bool endLevel;

  string nameLevel;
  string finalPhrase;
  string name;

  sf::Font font;
  sf::Text heartsText[2];
  sf::Text scoreText[2];
  sf::Text endLevelText[5];

  DynamicEntityList *entities;
  list<Character *> characters;
  list<Obstacle *> obstacles;
  list<Item *> items;

  Player *playerOne;
  Player *playerTwo;

  ColliderManager *colliderManager;
  GraphicManager *graphicManager;

  sf::Texture *backgroundTexture;
  sf::RectangleShape background;

  sf::RectangleShape healthBox;

  sf::View *view;
  sf::RenderWindow *window;
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

  DynamicEntityList *GetDynamicEntityList() { return entities; }
  list<Character *> *GetListCharacters() { return &characters; }
  list<Obstacle *> *GetListObstacles() { return &obstacles; }
  list<Item *> *GetListItems() { return &items; }

  string GetNameLevel() { return nameLevel; }

  int GetScore() { return score; }

  bool GetIsCoop() { return isCoop; }
  bool GetEndLevel() { return endLevel; }

  Player *GetPlayer() { return playerOne; };
  void SetPlayerOne(Player *p) { playerOne = p; };
  void SetPlayerTwo(Player *p) { playerTwo = p; };

  void SetViewCenter();

  void ClearAll();

  virtual float GetSizeX() { return sizeX; }
};
