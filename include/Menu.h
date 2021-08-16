#pragma once

#include "stdfx.h"
#include "Entity.h"

class GraphicManager;
class Level;
class Menu : public Entity
{
protected:
  int selectedItemIndex;
  bool isPlaying;
  bool isPaused;
  bool isChapters;
  bool isRanking;
  bool isModMenu;

  sf::Vector2f centerPosition;

public:
  Menu(GraphicManager *graphicManager);
  ~Menu();

  virtual void Draw(sf::RenderWindow *window, sf::View *view) = 0;

  virtual void MoveUp() = 0;
  virtual void MoveDown() = 0;
  void Draw(sf::RenderWindow &window);
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

  void SetModMenu(bool state) { isModMenu = state; }
  bool GetModMenu() { return isModMenu; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};