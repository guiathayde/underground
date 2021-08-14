#pragma once

#include "stdfx.h"

class GraphicManager;
class Level;
class Menu
{
protected:
  int selectedItemIndex;
  bool isPlaying;
  bool isPaused;
  bool isChapters;
  bool isRanking;

  sf::Vector2f centerPosition;

public:
  Menu(GraphicManager *graphicManager);
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

  void SetChapters(bool state) { isChapters = state; }
  bool GetChapters() { return isChapters; }

  void SetRanking(bool state) { isRanking = state; }
  bool GetRanking() { return isRanking; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};