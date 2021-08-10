#pragma once

#include "stdfx.h"
#include "Player.h"
#include "DynamicEntityList.h"
#include "Obstacle.h"

class GraphicManager;
class ColliderManager;
class Level : public Entity
{
protected:
  int level;
  int n_entities;

  DynamicEntityList *entities;
  list<Character *> characters;
  list<Obstacle *> platforms;

  Player *playerOne;
  
  ColliderManager *colliderManager;
  GraphicManager *graphicManager;
  

  sf::RectangleShape background;

  float sizeX;

public:
  Level(GraphicManager *graphicManager, ColliderManager *colliderManager);
  virtual ~Level();

  virtual void Initialize() = 0;
  virtual void InitializeCharacters() = 0;
  void Update(float deltaTime);
  void CheckCollison();
  void Draw(sf::RenderWindow &window);
  
  Player *GetPlayer(){return playerOne;};
  void SetPlayer(Player *p) { playerOne = p; };
  
  void ClearAll();

  virtual float GetSizeX() { return sizeX; }

};
