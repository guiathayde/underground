#pragma once

#include "stdfx.h"
#include "Player.h"

using namespace std;

static const float VIEW_WIDTH = 1280.0f;
static const float VIEW_HEIGHT = 720.0f;

class Level;
class GraphicManager
{
protected:
  sf::RenderWindow *window;
  sf::View *view;

  map<const char *, sf::Texture *> textures;

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

  bool WindowisOpen(){return window->isOpen();}

  sf::RenderWindow *GetWindow() { return window; }
  sf::View *GetView() { return view; }
  Level* GetCurrentLevel(){return currentLevel;}

  void Draw();
};