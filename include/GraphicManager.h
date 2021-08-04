#pragma once

#include <map>
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "MainMenu.h"
#include "PauseMenu.h"
#include "Player.h"

static const float VIEW_WIDTH = 1280.0f;
static const float VIEW_HEIGHT = 720.0f;

class Level;
class GraphicManager
{
protected:
  sf::RenderWindow *window;
  sf::View *view;

  map<const char *, sf::Texture *> textures;

  MainMenu *mainMenu;
  PauseMenu *pauseMenu;

  Level *currentLevel;
  Player *playerOne;
  Player *playerTwo;

public:
  GraphicManager();
  ~GraphicManager();

  void ResizeView();
  void SetViewCenter();

  void LoadTexture();
  void InsertTexture(const char *name, sf::Texture *texture);
  sf::Texture *GetTexture(const char *name);

  void SetCurrentLevel(Level *level) { currentLevel = level; }
  void SetPlayerOne(Player *player) { playerOne = player; }
  void SetPlayerTwo(Player *player) { playerTwo = player; }

  sf::RenderWindow *GetWindow() { return window; }
  sf::View *GetView() { return view; }

  void Draw();
};