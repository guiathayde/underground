#include "stdfx.h"

class Level;
class SaveManager
{
private:
  Level *currentLevel;

public:
  SaveManager(Level *level);
  ~SaveManager();

  void SaveLevel(string nameLevel);
  void ReadLevel(string nameLevel);
};