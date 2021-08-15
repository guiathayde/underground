#include "Level.h"

class LevelSubway : public Level
{
private:

  int enemiesNum;
  sf::Vector2f backgroundSize;
  sf::Vector2f basePlatformPosition;

public:
  LevelSubway(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelSubway();

  void InitializeCharacters();
  void Initialize();

  float GetSizeX() { return sizeX; }
};