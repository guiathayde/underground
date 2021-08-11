#include "Level.h"

class LevelSubway : public Level
{
private:
  int enemiesNum;

public:
  LevelSubway(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelSubway();

  void InitializeCharacters();
  void Initialize();

  float GetSizeX() { return sizeX; }
};