#pragma once

#include "stdfx.h"

class Level;
class Menu
{
protected:
  int selectedItemIndex;
  bool isPlaying;
  bool isPaused;

  sf::Vector2f centerPosition;

public:
  Menu(float width, float height);
  ~Menu();

  virtual void Draw(sf::RenderWindow *window, sf::View *view) = 0;

  virtual void MoveUp() = 0;
  virtual void MoveDown() = 0;

  virtual int SelectItem(sf::Event event, Level *level) = 0;
  int GetPressedItem() { return selectedItemIndex; }

  void SetPlaying(bool state) { isPlaying = state; }
  bool GetPlaying() { return isPlaying; }

  void SetPause(bool state) { isPaused = state; }
  bool GetPause() { return isPaused; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};