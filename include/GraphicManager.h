#pragma once

#include "stdfx.h"

using namespace std;

static const float VIEW_WIDTH = 1280.0f;
static const float VIEW_HEIGHT = 720.0f;


class GraphicManager
{
protected:
  sf::RenderWindow *window;
  sf::View *view;

  map<string, sf::Texture *> textures;

public:

  GraphicManager();
  ~GraphicManager();

  void ResizeView();
  void LoadTexture();
  void InsertTexture(string name, sf::Texture *texture);
  void Draw();
  

  bool WindowisOpen(){return window->isOpen();}

  sf::Texture *GetTexture(string name);
  sf::RenderWindow *GetWindow() { return window; }
  sf::View *GetView() { return view; }
  
};