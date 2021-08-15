#include "Level.h"

class LevelOverground : public Level
{
private:

  int enemiesNum;
  sf::Vector2f basePlatformPosition;


public:
  LevelOverground(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelOverground();

  void InitializeCharacters();
  void Initialize();

  float GetSizeX() { return sizeX; }
};