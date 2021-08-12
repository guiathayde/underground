#include "Level.h"

class LevelOverground : public Level
{
private:
  int enemiesNum;

public:
  LevelOverground(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelOverground();

  void InitializeCharacters();
  void Initialize();

  float GetSizeX() { return sizeX; }
};