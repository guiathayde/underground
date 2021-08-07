#pragma once

#include "stdfx.h"
#include "DynamicEntityList.h"
#include "Entity.h"

class GraphicManager;
class GraphicCollider;
class Level : public Entity
{
protected:
  int level;
  int n_entities;

  DynamicEntityList *entities;
  list<Character *> characters;

  Player *playerOne;

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
  Player *GetPlayer();
  void SetPlayer(Player *p) { playerOne = p; };
  void ClearAll();

  virtual float GetSizeX() { return sizeX; }

  Player *GetPlayer();
};
