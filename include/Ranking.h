#pragma once

#include "stdfx.h"
#include "Menu.h"

#define RANK_MAX_SIZE 32

class Ranking : public Menu
{
private:
  int sizeWithRank;
  int scoreLevelOne;
  int scoreLevelTwo;
  int scoreLevelThree;

  map<const char *, int> ranking;

  sf::Font font;
  sf::RectangleShape background;
  sf::Text back[1];
  sf::Text name[RANK_MAX_SIZE];
  sf::Text score[RANK_MAX_SIZE];

public:
  Ranking(GraphicManager *graphicManager);
  ~Ranking();

  void Draw(sf::RenderWindow *window, sf::View *view);

  void MoveUp();
  void MoveDown();

  void SetScoreLevelOne(int score) { scoreLevelOne = score; }
  int GetScoreLevelOne() { return scoreLevelOne; }

  void SetScoreLevelTwo(int score) { scoreLevelTwo = score; }
  int GetScoreLevelTwo() { return scoreLevelTwo; }

  void SetScoreLevelThree(int score) { scoreLevelThree = score; }
  int GetScoreLevelThree() { return scoreLevelThree; }

  void InsertRank(const char *name, int score);
  void SetRank(const char *name, int score);

  int SelectItem(sf::Event event, Level *level);
};