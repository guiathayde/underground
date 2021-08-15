#include "Level.h"

class LevelOverground : public Level
{
private:
  int enemiesNum;

public:
  LevelOverground(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelOverground();

  void InitializeCharacters(DynamicEntityList* entities);
  void Initialize(DynamicEntityList* entities);

  float GetSizeX() { return sizeX; }
};