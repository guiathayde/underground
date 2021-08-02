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

void SetViewCenter(sf::View &view, sf::Vector2f playerPosition, Level &level, sf::RenderWindow &window)
{
  // code to set the view to not extrapolate the level limits borders
  sf::Vector2f viewCenter = level.GetPlayer()->GetPosition();

  // set in Y
  if (viewCenter.y + (view.getSize().y / 2.0f) >= static_cast<float>(window.getSize().y))
    viewCenter.y = static_cast<float>(window.getSize().y) - (view.getSize().y / 2.0f);
  if (viewCenter.y + (view.getSize().y / 2.0f) <= 0.0f)
    viewCenter.y = (view.getSize().y / 2.0f);

  // set in X
  if (viewCenter.x - (view.getSize().x / 2.0f) <= 0.0f)
    viewCenter.x = view.getSize().x / 2.0f;
  if (viewCenter.x + (view.getSize().x / 2.0f) >= level.GetSizeX())
    viewCenter.x = level.GetSizeX() - (view.getSize().x / 2.0f);

  view.setCenter(viewCenter);
}




int main()
{
  sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Underground");
  sf::View view(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1280.0f, 720.0f));

  MainMenu mainMenu(window.getSize().x, window.getSize().y);
  PauseMenu pauseMenu(window.getSize().x, window.getSize().y);

  sf::Texture background;
  background.loadFromFile("assets/background/levelOne.png");
  Level level(1, background, &view, 5000.0f);

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
          pauseMenu.SelectItem(event, mainMenu,level);

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
      SetViewCenter(view, level.GetPlayer()->GetPosition(), level, window);
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