#pragma once
#include "stdfx.h"

class Level;
class GraphicManager;
class DynamicEntityList;
class Ranking;
class Character;
class SaveManager
{
private:
  
  GraphicManager *currentGraphicManager;
  Level *currentLevel;
  DynamicEntityList *entities;
  list<Character *> characters;
  Ranking *currentRanking;
  string nameLevel;

public:
  SaveManager(GraphicManager *graphicManager, Ranking *ranking);
  ~SaveManager();

  string GetNameLevel() { return nameLevel; };
  DynamicEntityList *GetEntities() { return entities; };
  list<Character *> *GetCharacters() { return &characters; };

  void SaveLevel();
  void ReadLevel();

  void SaveScore();
  void ReadRanking();

  void SetLevel(Level* level) { currentLevel = level; }

};