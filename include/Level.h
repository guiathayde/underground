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
class Level : public Entity
{
protected:
  int level;
  int n_entities;
  int score;

  sf::Font font;
  sf::Text scoreText[2];

  DynamicEntityList *entities;
  list<Character *> characters;
  list<Obstacle *> platforms;
  list<Item *> items;

  Player *playerOne;
  Player *playerTwo;

  ColliderManager *colliderManager;
  GraphicManager *graphicManager;

  sf::RectangleShape background;
  sf::View *view;
  sf::RenderWindow *window;

  float sizeX;

public:
  Level(GraphicManager *graphicManager, ColliderManager *colliderManager);
  virtual ~Level();

  virtual void Initialize() = 0;
  virtual void InitializeCharacters() = 0;
  void Update(float deltaTime);
  void CheckCollison();
  void Draw(sf::RenderWindow &window);

  Player *GetPlayer() { return playerOne; };
  void SetPlayerOne(Player *p) { playerOne = p; };
  void SetPlayerTwo(Player *p) { playerTwo = p; };

  void SetViewCenter();

  void ClearAll();

  virtual float GetSizeX() { return sizeX; }
};
