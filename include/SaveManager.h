#pragma once
#include "stdfx.h"

class Level;
class GraphicManager;
class DynamicEntityList;
class Ranking;
class Character;
class Obstacle;
class SaveManager
{
private:
  
  GraphicManager *currentGraphicManager;
  Level *currentLevel;
 
  Ranking *currentRanking;
  string nameLevel;

public:
  SaveManager(GraphicManager *graphicManager, Ranking *ranking);
  ~SaveManager();

  string GetNameLevel() { return nameLevel; };

  void SaveLevel();
  void ReadLevel();
  
  void SaveCharacters();
  void ReadCharacters();

  void SaveObstacles();
  void ReadObstacles();

  void SaveItems();
  void ReadItems();

  void SaveScore();
  void ReadRanking();

  void SetLevel(Level* level) { currentLevel = level; }

};