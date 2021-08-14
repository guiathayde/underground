#include "stdfx.h"

class Level;
class Ranking;
class SaveManager
{
private:
  Level *currentLevel;
  Ranking *currentRanking;

public:
  SaveManager(Level *level, Ranking *ranking);
  ~SaveManager();

  void SaveLevel();
  void ReadLevel();

  void SaveScore();
  void ReadRanking();
};