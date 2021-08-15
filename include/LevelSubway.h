#include "Level.h"

class LevelSubway : public Level
{
private:
  int enemiesNum;

public:
  LevelSubway(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelSubway();

  void InitializeCharacters(DynamicEntityList* entities);
  void Initialize(DynamicEntityList* entities);

  float GetSizeX() { return sizeX; }
};