#pragma once

#include "Level.h"

class LevelSewer : public Level
{
private:
  int enemiesNum;

public:
  LevelSewer(sf::View *view, sf::RenderWindow *window);
  ~LevelSewer();

  void Initialize(sf::RenderWindow &window, map<const char *, sf::Texture *> *textures);
};