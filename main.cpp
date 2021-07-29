#include <vector>
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Level.h"
#include "MainMenu.h"
#include "PauseMenu.h"

using std::cout;
using std::endl;

static const float VIEW_WIDTH = 1280.0f;
static const float VIEW_HEIGHT = 720.0f;

void ResizeView(const sf::RenderWindow &window, sf::View &view)
{
  float aspectRatio = float(window.getSize().x / float(window.getSize().y));
  view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Underground");
  sf::View view(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1280.0f, 720.0f));

  MainMenu mainMenu(window.getSize().x, window.getSize().y);
  PauseMenu pauseMenu(window.getSize().x, window.getSize().y);

  sf::Texture background;
  Level level(1, background);

  float deltaTime = 0.0f;
  sf::Clock clock;

  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();
    // solution when resizing the window and the player falls
    if (deltaTime > 1.0f / 20.0f)
      deltaTime = 1.0f / 20.0f;

    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::Resized:
        ResizeView(window, view);
        break;

      case sf::Event::KeyReleased:
      {
        if (event.key.code == sf::Keyboard::Escape && pauseMenu.GetPause())
          pauseMenu.SetPause(false);
        else if (event.key.code == sf::Keyboard::Escape)
          pauseMenu.SetPause(true);
        else if (!mainMenu.GetPlaying())
          mainMenu.SelectItem(event, window, level);

        if (pauseMenu.GetPause())
          pauseMenu.SelectItem(event, mainMenu);

        break;
      }

      default:
        break;
      }
    }

    window.clear();

    if (pauseMenu.GetPause() && mainMenu.GetPlaying())
    {
      level.Draw(window);
      pauseMenu.Draw(window, view);
    }
    else if (mainMenu.GetPlaying())
    {
      level.Update(deltaTime);
      level.CheckCollison();
      view.setCenter(level.GetPlayer()->GetPosition());
      level.Draw(window);
    }
    else if (!mainMenu.GetPlaying())
    {
      view.setCenter(mainMenu.GetCenterPosition());
      mainMenu.Draw(window);
    }

    window.setView(view);
    window.display();
  }

  return 0;
}